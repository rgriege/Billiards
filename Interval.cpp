#include "./Interval.h"
#include <sstream>
#include <string>
#include <cmath>

Interval::Interval() {
  left = 0;
  right = 0;
}

Interval::Interval(GLfloat _left, GLfloat _right) {
  left = _left;
  right = _right;
}

float Interval::length() {
  return right - left;
}

bool Interval::contains(GLfloat x) {
  return x >= left && x <= right;
}

bool Interval::overlaps(Interval other) {
  return contains(other.left) || other.contains(left);
}

GLfloat Interval::overlap_dist(Interval other) {
  GLfloat maxDiff = (length() > other.length()) ? length() : other.length();
  GLfloat diff1 = right - other.left;
  if (diff1 < 0 || diff1 > maxDiff) diff1 = 0;
  GLfloat diff2 = other.right - left;
  if (diff2 < 0 || diff2 > maxDiff) diff2 = 0;
  // return the smallest nonzero if one exists
  if (diff1 == 0 || diff2 == 0)
    return diff1 + diff2;
  else
    return (diff1 < diff2) ? diff1 : diff2;
}

string Interval::to_string() const {
  stringstream ssx, ssy;
  ssx << left;
  ssy << right;
  return "(" + ssx.str() + "," + ssy.str() + ")";
}
