#ifndef DISK_H
#define DISK_H

#include "./RigidBody.h"
#include "./math.h"
#include <string>
#include <iostream>
using namespace std;

class Disk: public RigidBody {
 public:
  Disk() { radius = 0; }
  Disk(GLfloat _radius);
  Interval project(Vec2 axis) {
    if (!axis.is_unit_vector())
      axis.normalize();

    GLfloat center_proj = get_center().dot(axis);
    return Interval(center_proj - radius, center_proj + radius);
  }
  virtual void draw() {
    glColor3f(color.r, color.g, color.b);
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    glBegin(GL_POLYGON);
    for (GLint i = 0; i < 60; i++) {
      glVertex2f(center.get_x()+radius*cos(i*PI/30),
        center.get_y()+radius*sin(i*PI/30));
    }
    glEnd();
  }
  void rotate(GLfloat radians) {}
  string get_type() { return "disk"; }
  GLfloat get_radius() { return radius; }

 protected:
  GLfloat radius;
};

#endif
