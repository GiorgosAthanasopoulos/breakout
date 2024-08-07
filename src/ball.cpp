#include "ball.hpp"
#include "config.hpp"
#include "util.hpp"
#include <raylib.h>

Ball::Ball() {
  Resize(GetWindowSize(), GetWindowSize());
  Reset();
}

void Ball::Resize(Vector2 old, Vector2 neew) {
  speed = CalculateSpeed(BALL_SPEED_RATIO);
  size = CalculateSize(BALL_SIZE_RATIO);
  pos = MaintainPosAfterResize(old, neew, pos);
}

void Ball::Update() {
  Vector2 vel = {0, 0};
  // TODO: update ball pos/trajectory based on angle
  pos += vel * GetFrameTime();
  pos = BallBoundaryCheck(pos, size);
}

void Ball::Draw() { DrawCircleV(pos, size.x / 2, BALL_COLOR); }

Ball::~Ball() {}

Rectangle Ball::GetRec() { return {pos.x, pos.y, size.x, size.y}; }

void Ball::Reset() {
  pos = {GetWindowWidth() / 2,
         GetWindowHeight() - BALL_BOTTOM_PADDING * size.y};
  angle = GetRandomValue(91, 179);
}
