#pragma once

#include <raylib.h>

class Paddle {
public:
  Paddle();
  void Resize(Vector2 old, Vector2 neew);
  void Update();
  void Draw();
  ~Paddle();

  Rectangle GetRec();
  void Reset();

private:
  Vector2 pos, size, speed;
};
