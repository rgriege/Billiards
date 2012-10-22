#ifndef POLYGON_H
#define POLYGON_H

#include <vector>
#include <string>
#include "./RigidBody.h"
using namespace std;

class Polygon: public RigidBody {
 public:
  explicit Polygon(vector<Vec2> _vertices);
  void draw() {
    glColor3f(color.r, color.g, color.b);
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    glBegin(GL_POLYGON);
    GLint len = vertices.size();
    for (GLint i = 0; i < len; i++) {
      glVertex2f(center.get_x() + vertices[i].get_x(),
        center.get_y() + vertices[i].get_y());
    }
    glEnd();
  }
  Interval project(Vec2 axis) {
    if (!axis.is_unit_vector())
      axis.normalize();

    GLfloat vertex_projection = vertices[0].dot(axis);
    Interval result(vertex_projection, vertex_projection);
    GLint len = vertices.size();
    for (GLint i = 1; i < len; i++) {
      vertex_projection = vertices[i].dot(axis);
      if (vertex_projection < result.get_left())
        result.set_left(vertex_projection);
      else if (vertex_projection > result.get_right())
        result.set_right(vertex_projection);
    }
    result.set_left(result.get_left() + center.dot(axis));
    result.set_right(result.get_right() + center.dot(axis));
    return result;
  }
  void rotate(GLfloat radians) {}
  vector<Vec2> get_edge_perps();
  Vec2 get_closest_vertex(const Vec2 target) const;
  string get_type() { return "polygon"; }
 
 protected:
  Polygon() {}
  vector<Vec2> vertices;
};

#endif
