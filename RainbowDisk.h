#ifndef RAINBOWDISK_H
#define RAINBOWDISK_H

#include "../CSQ/Disk.h"
using namespace std;

class RainbowDisk : public Disk {
 public:
  explicit RainbowDisk(GLfloat radius);
  void draw();
  void move(GLfloat time);

 private:
  Vec2 trail[7];
  GLint lead_color_index;
  GLint frame_counter;
};
#endif
