#include "./Matrix2.h"
#include "./math.h"
using namespace std;

Matrix2::Matrix2(GLfloat rotation) {
  ul = cos(rotation);
  ur = -sin(rotation);
  dl = sin(rotation);
  dr = cos(rotation);
}
