#pragma once

#include "ball.hpp"
#include "block.hpp"
#include "paddle.hpp"
#include <raylib.h>
#include <vector>

class Breakout {
public:
  Breakout();
  bool ShouldClose();
  void Resize(Vector2 old, Vector2 neew);
  void Update();
  void Draw();
  ~Breakout();

private:
  Vector2 winSize;

  Paddle paddle;
  Ball ball;
  std::vector<Block> blocks;

  void Restart();
};
