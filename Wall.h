#ifndef WALL_H
#define WALL_H

#include "../CSQ/Polygon.h"
#include "../CSQ/Common.h"
using namespace std;

class Wall : public Polygon {
 public:
  //Wall(GLfloat x, GLfloat y, GLfloat width, GLfloat height) : 
    //Wall(x, y, width, height, 0) {}
  Wall(GLfloat x, GLfloat y, GLfloat width, GLfloat height, 
    GLfloat rotation=0);
};

#endif
