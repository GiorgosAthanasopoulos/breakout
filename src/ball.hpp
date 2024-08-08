#pragma once

#include <raylib.h>
class Ball {
public:
  Ball();
  void Resize(Vector2 old, Vector2 neew);
  void Update();
  void Draw();
  ~Ball();

  void Reset();

  Vector2 GetPos();
  float GetRadius();
  Vector2 GetSpeed();

  void SetPos(Vector2 pos);
  void SetSpeed(Vector2 speed);

private:
  Vector2 pos, speed;
  float radius;
};
