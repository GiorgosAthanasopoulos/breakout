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
  radius = CalculateSize(BALL_SIZE_RATIO).x;
  pos = MaintainPosAfterResize(old, neew, pos);
}

void Ball::Update() {
  if (pos.x <= 0 || pos.x + radius >= GetWindowWidth()) {
    speed.x *= -1;
  }
  if (pos.y <= 0 || pos.y + radius >= GetWindowHeight()) {
    speed.y *= -1;
  }
  pos += speed * GetFrameTime();
}

void Ball::Draw() { DrawCircleV(pos, radius, BALL_COLOR); }

Ball::~Ball() {}

void Ball::Reset() {
  pos = {GetWindowWidth() / 2,
         GetWindowHeight() - BALL_BOTTOM_PADDING * radius * 2};
  speed.y = speed.y < 0 ? -speed.y : speed.y;
}

Vector2 Ball::GetPos() { return pos; }

float Ball::GetRadius() { return radius; }

Vector2 Ball::GetSpeed() { return speed; }

void Ball::SetSpeed(Vector2 speed) { this->speed = speed; }

void Ball ::SetPos(Vector2 pos) { this->pos = pos; }
