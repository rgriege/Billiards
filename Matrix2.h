#ifndef MATRIX_H
#define MATRIX_H

#include "./Common.h"
using namespace std;

class Matrix2 {
 public:
  explicit Matrix2(GLfloat rotation);
  GLfloat get_ul() const { return ul; }
  GLfloat get_ur() const { return ur; }
  GLfloat get_dl() const { return dl; }
  GLfloat get_dr() const { return dr; }
 private:
  GLfloat ul, ur, dl, dr;
};

#endif
