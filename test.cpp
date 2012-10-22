#include <iostream>
#include "../CSQ/Polygon.h"
#include "../CSQ/Vec2.h"
#include "../CSQ/RigidBody.h"
using namespace std;

int main() {
  Polygon p(10, 10);
  p.translate(Vec2(10, 10));
  return 0;
}
