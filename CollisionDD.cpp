#include "./CollisionDD.h"
using namespace std;

CollisionDD::CollisionDD(Disk &_disk1, Disk &_disk2) : 
                         Collision(_disk1, _disk2) {
  disk1 = &_disk1;
  disk2 = &_disk2;
  c2c_vec =(*disk2).get_center() - (*disk1).get_center();
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

void CollisionDD::find_possible_axes() {
  possible_axes.push_back(c2c_vec);
}

void CollisionDD::find_collision_vector() {
  Interval int1 = disk1->project(c2c_vec);
  Interval int2 = disk2->project(c2c_vec);
  GLfloat dist = int1.overlap_dist(int2);
  collision_axis = c2c_vec.get_unit_vector();
  collision_vector = dist*collision_axis;
}

void CollisionDD::find_impact_point() {
  impact_point = (*disk1).get_center();
  impact_point += (*disk2).get_center();
  impact_point = 0.5*impact_point;
}
