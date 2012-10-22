#ifndef VEC2_H
#define VEC2_H

#include <string>
#include "./Common.h"
#include "./Matrix2.h"
using namespace std;

class Vec2 {
 public:
  Vec2();
  Vec2(const Vec2 &other);
  Vec2(GLfloat _x, GLfloat _y);
  GLfloat get_x() { return x; }
  GLfloat get_y() { return y; }
  GLfloat magnitude() const;
  GLfloat mag_squared() const;
  void normalize();
  Vec2 get_unit_vector() const;
  bool is_unit_vector() const;
  Vec2 operator+(const Vec2 other) const;
  Vec2 operator+=(const Vec2 other);
  Vec2 operator-(const Vec2 other) const;
  Vec2 operator-=(const Vec2 other);
  friend Vec2 operator*(const GLfloat n, const Vec2 vec);
  friend Vec2 operator*=(const GLfloat n, Vec2 vec);
  friend Vec2 operator*(const Matrix2 mat, const Vec2 &vec);
  void rotate(GLfloat radians);
  GLfloat dot(const Vec2 other) const;
  Vec2 project(const Vec2 axis) const;
  Vec2 get_perp(const bool left) const;
  Vec2 get_inverse() const;
  void invert();
  bool equals(const Vec2 other) const;
  bool is_zero() const;
  bool shares_quadrant(const Vec2 other) const;
  Vec2 copy() const;
  string to_string() const;
  static const Vec2 X_AXIS, Y_AXIS;

 private:
  Vec2 plus(const Vec2 other) const;
  void plus_equals(const Vec2 other);
  Vec2 minus(const Vec2 other) const;
  void minus_equals(const Vec2 other);
  Vec2 scale(const GLfloat n) const;
  void scale_equals(const GLfloat n);
  GLfloat x, y;
};

#endif
