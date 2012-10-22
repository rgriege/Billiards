#ifndef LEVEL_H
#define LEVEL_H

#include "../CSQ/World.h"
#include "./Wall.h"
#include "./constants.h"
#include "./RainbowDisk.h"
class Level : public World {
 public:
  Level();
  void setup(GLint level_num);
  void draw_objects();
  void apply_cue_impulse(Vec2 impulse);
  void draw_aim_line(const Vec2& start, const Vec2& end);
  bool goal_reached();
  GLint get_num_moves() { return num_moves; }
  void toggle_rainbows();
  void add_borders();
 private:
  GLint num_moves;
  Disk *target, *goal, *cue;
  bool rainbow_mode;
};

#endif
