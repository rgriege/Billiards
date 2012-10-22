#include "./CollisionDP.h"
#include <iostream>
#include <sstream>
using namespace std;

CollisionDP::CollisionDP(Disk &_disk, Polygon &_polygon) :
                         Collision(_disk, _polygon) {
  disk = &_disk;
  polygon = &_polygon;
  c2c_vec =(*polygon).get_center() - (*disk).get_center();
  close = bounds_overlap();
  if (close) {
    find_possible_axes();
    find_collision_vector();
    if (!collision_vector.is_zero()) {
      move_to_tangency();
      find_impact_point();
      find_radii();
      find_ipv();
      find_impulse();
    }
  }
}

void CollisionDP::find_possible_axes() {
  possible_axes = polygon->get_edge_perps();
  for (GLint i = 0; i < possible_axes.size(); i++)
    if (!possible_axes[i].shares_quadrant(c2c_vec))
      possible_axes[i].invert();
  possible_axes.push_back(polygon->get_closest_vertex(disk->get_center())
    - disk->get_center());
}

void CollisionDP::find_collision_vector() {
  GLfloat min_overlap = 0;
  for (GLint i = 0; i < possible_axes.size(); i++) {
    GLfloat overlap_on_axis = (*disk).project(possible_axes[i]).overlap_dist(
      (*polygon).project(possible_axes[i]));
    if (overlap_on_axis == 0) {
      return;
    } else if (overlap_on_axis < min_overlap || min_overlap == 0) {
      min_overlap = overlap_on_axis;
      collision_axis = possible_axes[i];
    }
  }
  collision_axis.normalize();
  collision_vector = min_overlap*collision_axis;
}

void CollisionDP::find_impact_point() {
  impact_point = disk->get_center();
  impact_point += disk->get_radius()*collision_axis;
}
