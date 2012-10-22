#ifndef WORLD_H
#define WORLD_H

#include <vector>
#include "./Vec2.h"
#include "./Polygon.h"
#include "./Disk.h"
#include "./CollisionDD.h"
#include "./CollisionDP.h"
#include "./Collision.h"
#include "./Common.h"

class World {
 public:
  void move_bodies(GLfloat time);
  void resolve_collisions();
  void draw_objects() {
    for (GLint i = 0; i < actives.size(); i++)
      actives[i]->draw();
    /*for (GLint i = 0; i < stills.size(); i++) {
      stills[i]->draw();
    }*/
  }
  void add_drag_force(GLfloat drag);
  void add_still(Polygon *p);
  void remove_still(Polygon *p);
  void clear_stills() { stills.clear(); }
  void add_active(Disk *d);
  void remove_active(Disk *d);
 protected:
  vector<Polygon*> stills;
  vector<Disk*> actives;
  GLfloat drag;
};

#endif
