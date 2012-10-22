#include "./Polygon.h"
#include <vector>
#include <iostream>
using namespace std;

Polygon::Polygon(vector<Vec2> _vertices) {
  vertices = _vertices;
}

/*void Polygon::draw() {
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

Interval Polygon::project(Vec2 axis) {
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
}*/

vector<Vec2> Polygon::get_edge_perps() {
  vector<Vec2> result;
  GLint len = vertices.size();
  result.push_back((vertices[0] - vertices[len-1]).get_perp(true));
  for (GLint i = 1; i < len; i++) {
    result.push_back((vertices[i] - vertices[i-1]).get_perp(true));
  }
  return result;
}

Vec2 Polygon::get_closest_vertex(const Vec2 target) const {
  GLfloat min_dist = (vertices[0]+center-target).mag_squared();
  Vec2 result = vertices[0];
  GLint len = vertices.size();
  for (GLint i = 1; i < len; i++) {
    GLfloat dist = (vertices[i]+center-target).mag_squared();
    if(dist < min_dist) {
       min_dist = dist;
       result = vertices[i];
    }
  }
  return result+center;
}

