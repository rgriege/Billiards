#include "./Disk.h"
#include <string>
#include "./math.h"
using namespace std;

Disk::Disk(GLfloat _radius) {
  radius = _radius;
}

/*Interval Disk::project(Vec2 axis) {
  if (!axis.is_unit_vector())
    axis.normalize();

  float center_proj = get_center().dot(axis);
  return Interval(center_proj - radius, center_proj + radius);
}*/

/*void Disk::draw() {
  glColor3f(color.r, color.g, color.b);
  glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
  glBegin(GL_POLYGON);
  for (int i = 0; i < 60; i++) {
    glVertex2f(center.get_x()+radius*cos(i*PI/30),
      center.get_y()+radius*sin(i*PI/30));
  }
  glEnd();
}*/
