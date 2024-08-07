#include "paddle.hpp"
#include "config.hpp"
#include "util.hpp"
#include <raylib.h>

Paddle::Paddle() {
  Resize(GetWindowSize(), GetWindowSize());
  Reset();
}

void Paddle::Resize(Vector2 old, Vector2 neew) {
  size = CalculateSize({PADDLE_SIZE_RATIO_X, PADDLE_SIZE_RATIO_Y});
  speed = CalculateSpeed(PADDLE_SPEED_RATIO);
  pos = MaintainPosAfterResize(old, neew, pos);
}

void Paddle::Update() {
  Vector2 vel = {0, 0};
  if (IsKeyDown(KEY_PADDLE_MOVE_LEFT) && IsKeyDown(KEY_PADDLE_MOVE_RIGHT)) {
    vel.x = 0;
  } else if (IsKeyDown(KEY_PADDLE_MOVE_LEFT)) {
    vel.x = -speed.x;
  } else if (IsKeyDown(KEY_PADDLE_MOVE_RIGHT)) {
    vel.x = speed.x;
  }
  pos += vel * GetFrameTime();
  pos = PaddleBoundaryCheck(pos, size);
}

void Paddle::Draw() { DrawRectangleV(pos, size, PADDLE_COLOR); }

Paddle::~Paddle() {}

Rectangle Paddle::GetRec() { return {pos.x, pos.y, size.x, size.y}; }

void Paddle::Reset() {
  pos = {GetWindowWidth() / 2 - size.x / 2,
         GetWindowHeight() - PADDLE_BOTTOM_PADDING * size.y};
}
