#include "./Vec2.h"
#include <string>
#include <sstream>
#include "./math.h"

const Vec2 Vec2::X_AXIS(1, 0);
const Vec2 Vec2::Y_AXIS(0, 1);

Vec2::Vec2() {
  x = 0;
  y = 0;
}

Vec2::Vec2(const Vec2 &other) {
  x = other.x;
  y = other.y;
}

Vec2::Vec2(GLfloat _x, GLfloat _y) {
  x = _x;
  y = _y;
}

GLfloat Vec2::magnitude() const {
  return sqrt(mag_squared());
}

GLfloat Vec2::mag_squared() const {
  return x*x + y*y;
}

void Vec2::normalize() {
  scale_equals(1/magnitude());
}

Vec2 Vec2::get_unit_vector() const {
  if (is_unit_vector())
    return copy();
  else
    return scale(1/magnitude());
}
bool Vec2::is_unit_vector() const {
  return mag_squared() == 1;
}

Vec2 Vec2::operator+(const Vec2 other) const {
  return plus(other);
}

Vec2 Vec2::operator+=(const Vec2 other) {
  plus_equals(other);
  return *this;
}

Vec2 Vec2::operator-(const Vec2 other) const {
  return minus(other);
}

Vec2 Vec2::operator-=(const Vec2 other) {
  minus_equals(other);
  return *this;
}

Vec2 operator*(const GLfloat n, const Vec2 vec) {
  return vec.scale(n);
}

Vec2 operator*=(const GLfloat n, Vec2 vec) {
  vec.scale_equals(n);
  return vec;
}

Vec2 operator*(const Matrix2 mat, const Vec2 &vec) {
  return Vec2(vec.x*mat.get_ul() + vec.y*mat.get_ur(),
    vec.x*mat.get_dl() + vec.y*mat.get_dr());
}

void Vec2::rotate(GLfloat radians) {
  Matrix2 mat(radians);
  GLfloat old_x = x;
  //x = x*cos(radians) - y*sin(radians);
  //y = old_x*sin(radians) + y*cos(radians);
  x = x*mat.get_ul() + y*mat.get_ur();
  y = old_x*mat.get_dl() + y*mat.get_dr();
}

Vec2 Vec2::plus(const Vec2 other) const {
  return Vec2(x+other.x, y+other.y);
}

void Vec2::plus_equals(const Vec2 other) {
  x += other.x;
  y += other.y;
}

Vec2 Vec2::minus(const Vec2 other) const {
  return Vec2(x-other.x, y-other.y);
}

void Vec2::minus_equals(const Vec2 other) {
  x -= other.x;
  y -= other.y;
}

Vec2 Vec2::scale(const GLfloat n) const {
  return Vec2(x*n, y*n);
}

void Vec2::scale_equals(const GLfloat n) {
  x *= n;
  y *= n;
}

float Vec2::dot(const Vec2 other) const {
  return x*other.x + y*other.y;
}

Vec2 Vec2::project(const Vec2 other) const {
  Vec2 axis = other.get_unit_vector();
  return axis.scale(dot(other));
}

Vec2 Vec2::get_perp(const bool left) const {
  if (left)
    return Vec2(y, -x);
  else
    return Vec2(-y, x);
}

Vec2 Vec2::get_inverse() const {
  return Vec2(-x, -y);
}

void Vec2::invert() {
  x = -x;
  y = -y;
}

bool Vec2::equals(const Vec2 other) const {
  return x == other.x && y == other.y;
}

bool Vec2::is_zero() const {
  return mag_squared() == 0;
}

bool Vec2::shares_quadrant(const Vec2 other) const {
  return dot(other) >= 0;
}

Vec2 Vec2::copy() const {
  return Vec2(x, y);
}

string Vec2::to_string() const {
  stringstream ssx, ssy;
  ssx << x;
  ssy << y;
  return "(" + ssx.str() + "," + ssy.str() + ")";
}
