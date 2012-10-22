#include "./Level.h"
#include <iostream>
#include <cstdio>
#include "./constants.h"
using namespace std;

Level::Level() {
  cue = new Disk(10);
  cue->set_color(kWhite);
  target = new Disk(10);
  target->set_color(kRed);
  goal = new Disk(10);
  goal->set_color(kBlack);
  add_active(cue);
  add_active(target);
  add_drag_force(drag_ratio);
  rainbow_mode = false;
}

void Level::draw_objects() {
  goal->draw();
  cue->set_color(kWhite);
  cue->draw();
  target->set_color(kRed);
  target->draw();
  for (GLint i = 0; i < actives.size(); i++)
    actives[i]->draw();
  for (GLint j = 0; j < stills.size(); j++) {
    stills[j]->set_color(kBrown);
    stills[j]->draw();
  }
}

void Level::apply_cue_impulse(Vec2 impulse) {
  cue->apply_impulse(impulse);
  num_moves++;
}

void Level::draw_aim_line(const Vec2& start, const Vec2& end) {
  Vec2 axis = (end - start).get_unit_vector();
  Vec2 line_start = cue->get_center() + cue->get_radius()*axis;
  Vec2 line_end = cue->get_center() + (8*cue->get_radius())*axis;
  glColor3f(1, 1, 1);
  glBegin(GL_LINES);
  glVertex2f(line_start.get_x(), line_start.get_y());
  glVertex2f(line_end.get_x(), line_end.get_y());
  glEnd();
}

bool Level::goal_reached() {
  GLfloat dist = (target->get_center() - goal->get_center()).mag_squared();
  GLfloat range = pow(target->get_radius() + goal->get_radius(), 2);
  return dist < range;
}

void Level::add_borders() {
  GLint thickness = 20;
  Wall* w1 = new Wall(window_width/2, thickness/2, window_width, thickness);
  add_still(w1);
  Wall* w2 = new Wall(window_width/2, window_height-thickness/2,
                         window_width, thickness);
  add_still(w2);
  Wall* w3 = new Wall(thickness/2, window_height/2, thickness, window_height);
  add_still(w3);
  Wall* w4 = new Wall(window_width-thickness/2, window_height/2,
                      thickness, window_height);
  add_still(w4);
}

void Level::setup(GLint level_num) {
  switch (level_num) {
    case 1:
      cue->reset(Vec2(200, 300));
      target->reset(Vec2(400, 300));
      goal->reset(Vec2(600, 300));
      clear_stills();
      add_borders();
      break;
    case 2: {
      cue->reset(Vec2(window_width/4, window_height/4));
      target->reset(Vec2(500, 300));
      goal->reset(Vec2(700, 500));
      Wall* w1 = new Wall(500, 400, 200, 20);
      add_still(w1);
      Wall* w2 = new Wall(590, 310, 20, 200);
      add_still(w2);
      break;
    }
    case 3: {
      cue->reset(Vec2(100, 100));
      target->reset(Vec2(350, 250));
      goal->reset(Vec2(750, 550));
      clear_stills();
      Wall* w1 = new Wall(400, 300, 500, 20, -PI/4);
      add_still(w1);
      add_borders();
      break;
    }
    case 4: {
      cue->reset(Vec2(400, 300));
      target->reset(Vec2(50, 50));
      goal->reset(Vec2(750, 550));
      clear_stills();
      Wall* w1 = new Wall(500, 300, 20, 220);
      add_still(w1);
      Wall* w2 = new Wall(400, 400, 200, 20);
      add_still(w2);
      Wall* w3 = new Wall(400, 200, 200, 20);
      add_still(w3);
      Wall* w4 = new Wall(700, 400, 20, 400);
      add_still(w4);
      add_borders();
    }
  }
}

void Level::toggle_rainbows() {
  Vec2 center = target->get_center();
  Vec2 velocity = target->get_velocity();
  remove_active(target);
  if (!rainbow_mode)
    target = new RainbowDisk(10);
  else
    target = new Disk(10);
  target->translate(center);
  target->set_velocity(velocity);
  add_active(target);
  rainbow_mode = !rainbow_mode;
}
