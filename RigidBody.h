#ifndef RIGIDBODY_H
#define RIGIDBODY_H

#include <string>
#include <iostream>
#include "./Vec2.h"
#include "./Interval.h"
#include "./Color.h"
using namespace std;

class RigidBody {
 public:
  RigidBody();
  virtual Interval project(Vec2 axis) = 0;
  void apply_impulse(Vec2 impulse);
  void apply_force(Vec2 force);
  virtual void move(GLfloat time);
  void translate(Vec2 change);
  virtual void rotate(GLfloat radians) = 0;
  Vec2 get_center() { return center; }
  Vec2 get_velocity() { return velocity; }
  Color get_color() { return color; }
  GLfloat get_mass() { return mass; }
  void set_color(const Color& _color);
  void reset(Vec2 _center);
  void set_velocity(Vec2 _velocity) { velocity = _velocity; }
  virtual void draw() = 0;
  virtual string get_type() = 0;
  void fix() { fixed = true; }
  bool is_fixed() { return fixed; }

 protected:
  Vec2 center, velocity, acceleration;
  GLfloat mass;
  Color color;
  bool fixed;
};

#endif
