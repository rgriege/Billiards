#ifndef INTERVAL_H
#define INTERVAL_H

#include <string>
#include "./Common.h"
using namespace std;

class Interval {
 public:
  Interval();
  Interval(GLfloat _left, GLfloat _right);
  GLfloat get_left() { return left; }
  GLfloat get_right() { return right; }
  void set_left(GLfloat _left) { left = _left; }
  void set_right(GLfloat _right) { right = _right; }
  GLfloat length();
  bool contains(GLfloat x);
  bool overlaps(Interval other);
  GLfloat overlap_dist(Interval other);
  string to_string() const;
 private:
  GLfloat left, right;
};

#endif
