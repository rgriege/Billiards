#ifndef COLLISION_H
#define COLLISION_H

#include <vector>
#include <string>
#include "./RigidBody.h"
using namespace std;

class Collision {
 public:
  Collision(RigidBody &_body1, RigidBody &_body2);
  bool exists();
  Vec2 get_impulse() { return impulse; }
  string to_string() const;
 protected:
  bool bounds_overlap();
  virtual void find_possible_axes() = 0;
  virtual void find_collision_vector() = 0;
  void move_to_tangency();
  virtual void find_impact_point() = 0;
  void find_radii();
  void find_ipv();
  void find_impulse();
  RigidBody *body1, *body2;
  Vec2 c2c_vec, collision_axis, collision_vector;
  Vec2 impact_point, radius1, radius2, ip_velocity;
  Vec2 impulse;
  GLfloat penetration_time;
  bool close, axis_from_body1;
  vector<Vec2> possible_axes;
};

#endif
