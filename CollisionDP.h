#ifndef COLLISIONDP_H
#define COLLISIONDP_H

#include "./Collision.h"
#include "./Disk.h"
#include "./Polygon.h"
using namespace std;

class CollisionDP : public Collision {
 public:
  CollisionDP(Disk &_disk, Polygon &_polygon);
 private:
  void find_possible_axes();
  void find_collision_vector();
  void find_impact_point();
  Disk *disk;
  Polygon *polygon;
};

#endif
