#include "./Collision.h"
#include <string>
#include <sstream>
#include <iostream>
#include "./math.h"

using namespace std;

Collision::Collision(RigidBody &_body1, RigidBody &_body2) {
  body1 = &_body1;
  body2 = &_body2;
}

bool Collision::bounds_overlap() {
  return (*body1).project(Vec2::X_AXIS).overlaps((*body2).project(Vec2::X_AXIS))
    && (*body1).project(Vec2::Y_AXIS).overlaps((*body2).project(Vec2::Y_AXIS));
}

bool Collision::exists() {
  return close && !collision_vector.is_zero();
}

void Collision::move_to_tangency() {
  GLfloat dist = collision_vector.magnitude();
  ip_velocity = body2->get_velocity();
  ip_velocity -= body1->get_velocity();
  GLfloat relative_speed = ip_velocity.dot(collision_axis);
  penetration_time = dist/relative_speed;
  body1->move(penetration_time);
  body2->move(penetration_time);
}

void Collision::find_radii() {
  radius1 = impact_point-(*body1).get_center();
  radius2 = impact_point-(*body2).get_center();
}

void Collision::find_ipv() {
  // found in move_to_tangency since no rotation
}

void Collision::find_impulse() {
  GLfloat numerator = -2*ip_velocity.dot(collision_axis);
  GLfloat denominator = (*body1).is_fixed() ? 0 : 1/(*body1).get_mass();
  denominator += (*body2).is_fixed() ? 0 : 1/(*body2).get_mass();
  impulse = (numerator/denominator)*collision_axis;
}

string Collision::to_string() const {
  string result = "Collision Data:\n";
  result += "Bounds overlap: ";
  stringstream ss;
  ss << close;
  result += ss.str();
  if (close) {
    result += "\nCollision axis: ";
    result += collision_axis.to_string();
    result += "\nOverlap: ";
    stringstream ss;
    ss << collision_vector.magnitude();
    result += ss.str();
    if (!collision_vector.is_zero()) {
      stringstream ss;
      ss << "\nPenetration time: " << penetration_time;
      result += ss.str();
      result += "\nImpact point: ";
      result += impact_point.to_string();
      result += "\nImpulse: ";
      result += impulse.to_string();
      result += "\nRemaining overlap: ";
      GLfloat x = body1->project(collision_axis)
                    .overlap_dist(body2->project(collision_axis));
      ss.str("");
      ss << x;
      result += ss.str();
    }
  }
  return result;
}
