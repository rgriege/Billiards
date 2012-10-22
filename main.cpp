#include <iostream>
#include <sys/time.h>
#include <vector>
#include <sstream>
#include <cstdio>
#include "../CSQ/Common.h"
#include "../CSQ/Color.h"
#include "../CSQ/Vec2.h"
#include "../CSQ/RigidBody.h"
#include "../CSQ/Disk.h"
#include "../CSQ/Polygon.h"
#include "../CSQ/World.h"
#include "./Level.h"
#include "./constants.h"
#include "./time.h"
using namespace std;

#define PI 3.1415

bool mouse_down = false;
Vec2 mouse_start;
Vec2 mouse_cur;
bool level_complete = false;
GLint level_num = 4;
GLint num_levels = 5;  // add 1 to actual number
Level level;
timeval last_time;

void Init() {
  glClearColor(kTan.r, kTan.g, kTan.b, 1);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluOrtho2D(0, window_width, 0, window_height);
  glMatrixMode(GL_MODELVIEW);
  level.setup(level_num);
  last_time.tv_sec = 0;
  glutPostRedisplay();
}

void draw_line(Vec2 v1, Vec2 v2) {
  glColor3f(0, 0, 0);
  glBegin(GL_LINES);
  glVertex2f(v1.get_x(), v1.get_y());
  glVertex2f(v2.get_x(), v2.get_y());
  glEnd();
}

void Display() {
  glClear(GL_COLOR_BUFFER_BIT);
  level.draw_objects();
  if (mouse_down) {
    draw_line(mouse_start, mouse_cur);
    level.draw_aim_line(mouse_cur, mouse_start);
  }
  glFlush();
}

void Mouse(int button, int button_mode, int x, int y) {
  if (!level_complete) {
    if (button == GLUT_LEFT_BUTTON) {
      if (button_mode == GLUT_DOWN) {
        mouse_start = Vec2(x, window_height-y);
        mouse_cur = mouse_start;
        mouse_down = true;
      } else if (button_mode == GLUT_UP) {
        Vec2 impulse = mouse_start;
        impulse-=(Vec2(x, window_height-y));
        impulse = power_ratio*impulse;
        level.apply_cue_impulse(impulse);
        mouse_down = false;
        if (!last_time.tv_sec)
          gettimeofday(&last_time, NULL);
      }
    }
  } else {
    level_num = (level_num + 1) % num_levels;
    level.setup(++level_num);
    mouse_start = Vec2(x, window_height-y);
    level_complete = false;
  }
}

void Motion(int x, int y) {
  mouse_cur = Vec2(x, window_height-y);
  glutPostRedisplay();
}

void Keyboard(unsigned char key, int xmouse, int ymouse) {
  if (key == 'r') {
    level.toggle_rainbows();
  }
}

void Idle() {
  if (!level_complete) {
    timeval current_time;
    gettimeofday(&current_time, NULL);
    GLfloat time_diff = current_time.tv_sec + current_time.tv_usec/1000000.0 -
                        (last_time.tv_sec + last_time.tv_usec/1000000.0);
    level.move_bodies(time_diff);
    last_time = current_time;
    level.resolve_collisions();
    if (level.goal_reached()) {
      stringstream ss;
      ss << "Level complete in " << level.get_num_moves() << " moves!";
      cout << ss.str() << endl;
      level_complete = true;
      last_time.tv_sec = 0;
    }
    glutPostRedisplay();
  }
}

int main(int argc, char** argv) {
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutInitWindowSize(window_width, window_height);
  glutInitWindowPosition(0, 0);
  glutCreateWindow("Billiards");
  glutDisplayFunc(Display);
  glutMouseFunc(Mouse);
  glutMotionFunc(Motion);
  glutKeyboardFunc(Keyboard);
  glutIdleFunc(Idle);
  Init();

  glutMainLoop();
}
