#pragma once

#include <raylib.h>
class Ball {
public:
  Ball();
  void Resize(Vector2 old, Vector2 neew);
  void Update();
  void Draw();
  ~Ball();

  Rectangle GetRec();
  void Reset();

private:
  Vector2 pos, size, speed;
  float angle;
};
