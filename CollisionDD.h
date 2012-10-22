#ifndef COLLISIONDD_H
#define COLLISIONDD_H

#include "./Collision.h"
#include "./Disk.h"
using namespace std;

class CollisionDD : public Collision {
 public:
  CollisionDD(Disk &_disk1, Disk &_disk2);
 private:
  void find_possible_axes();
  void find_collision_vector();
  void find_impact_point();
  Disk *disk1, *disk2;
};

#endif
