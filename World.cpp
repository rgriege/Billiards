#include "./World.h"
#include <vector>
#include <iostream>
#include <cstdio>
#include "./Collision.h"
#include "./CollisionDD.h"
#include "./CollisionDP.h"
using namespace std;

void World::move_bodies(GLfloat time) {
  for (GLint i = 0; i < actives.size(); i++) {
    if (drag != 0)
       actives[i]->apply_force(-drag*actives[i]->get_velocity());
    actives[i]->move(time);
  }
}

void World::resolve_collisions() {
  for (GLint i = 0; i < actives.size(); i++) {
    for (GLint j = 0; j < stills.size(); j++) {
      CollisionDP col(*actives[i], *stills[j]);
      if(col.exists())
        actives[i]->apply_impulse(col.get_impulse().get_inverse());
    }
    for (GLint j = 0; j < actives.size(); j++) {
      if (i != j) {
        CollisionDD col(*actives[i], *actives[j]);
        if (col.exists()) {
          actives[i]->apply_impulse(col.get_impulse().get_inverse());
          actives[j]->apply_impulse(col.get_impulse());
        }
      }
    }
  }
}

/*void World::draw_objects() {
  for (GLint i = 0; i < actives.size(); i++)
    actives[i]->draw();
  for (GLint i = 0; i < stills.size(); i++) {
    stills[i]->draw();
  }
}*/

void World::add_drag_force(GLfloat drag) {
  this->drag = drag;
}

void World::add_still(Polygon* p) {
  stills.push_back(p);
}

void World::remove_still(Polygon* p) {
  GLint i = 0;
  bool found = false;
  while(i < stills.size() && !found) {
    if (p == stills[i]) {
      stills.erase(stills.begin()+i);
      found = true;
    }
    i++;
  }
}

void World::add_active(Disk* d) {
  actives.push_back(d);
}

void World::remove_active(Disk* d) {
  GLint i = 0;
  bool found = false;
  while(i < actives.size() && !found) {
    if (d == actives[i]) {
      actives.erase(actives.begin()+i);
      found = true;
    }
    i++;  
  }
}
