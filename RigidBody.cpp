#include "./RigidBody.h"

using namespace std;

RigidBody::RigidBody() {
  mass = 1;
  fixed = false;
  color = kBlack;
  center = Vec2();
  velocity = Vec2();
  acceleration = Vec2();
}

void RigidBody::apply_impulse(Vec2 impulse) {
  velocity += (1/mass)*impulse;
}

void RigidBody::apply_force(Vec2 force) {
  acceleration += (1/mass)*force;
}

void RigidBody::move(GLfloat time) {
  center += time*velocity;
  velocity += time*acceleration;
  acceleration = Vec2(0, 0);
}

void RigidBody::translate(Vec2 change) {
  center += change;
}

void RigidBody::set_color(const Color& _color) {
  color = _color;
}

void RigidBody::reset(Vec2 _center) {
  center = _center;
  velocity = Vec2();
}
