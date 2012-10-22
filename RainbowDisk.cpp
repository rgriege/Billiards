#include "./RainbowDisk.h"
#include "./math.h"
using namespace std;

RainbowDisk::RainbowDisk(GLfloat radius) {
  this->radius = radius;
  lead_color_index = 0;
  frame_counter = 0;
  for (GLint i = 0; i < 7; i++)
    trail[i] = center;
}

void RainbowDisk::draw() {
  for (GLint i = 7; i >= 0; i--) {
    Color color = kRainbow[(lead_color_index+i)%7];
    glColor3f(color.r, color.g, color.b);
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    glBegin(GL_POLYGON);
    for (GLint j = 0; j < 60; j++) {
      glVertex2f(trail[i].get_x()+radius*cos(j*PI/30),
        trail[i].get_y()+radius*sin(j*PI/30));
    }
    glEnd();
  }
  lead_color_index = (lead_color_index+1)%7;
}

void RainbowDisk::move(GLfloat time) {
  center += time*velocity;
  velocity += time*acceleration;
  acceleration = Vec2(0, 0);

  if (frame_counter == 0) {
    for (GLint i = 6; i > 0; i--)
      trail[i] = trail[i-1];
  }
  trail[0] = center;
  frame_counter = (frame_counter+1)%10;
}
