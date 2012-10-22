#include "./Wall.h"
#include <vector>
#include <cstdio>
#include <iostream>
using namespace std;

Wall::Wall(GLfloat x, GLfloat y, GLfloat width, GLfloat height,
           GLfloat rotation) {
  vertices.push_back(Vec2(width/2, height/2));
  vertices.push_back(Vec2(-width/2, height/2));
  vertices.push_back(Vec2(-width/2, -height/2));
  vertices.push_back(Vec2(width/2, -height/2));
  translate(Vec2(x, y));
  fix();
  set_color(kBrown);
  for (GLint i = 0; i < 4; i++) {
    vertices[i].rotate(rotation);
  }
}
