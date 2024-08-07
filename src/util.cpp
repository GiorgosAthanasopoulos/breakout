#include "util.hpp"
#include <raylib.h>

float GetWindowWidth() { return GetRenderWidth(); }
float GetWindowHeight() { return GetRenderHeight(); }
Vector2 GetWindowSize() { return {GetWindowWidth(), GetWindowHeight()}; }

Vector2 operator/(Vector2 a, float b) { return {a.x / b, a.y / b}; }
Vector2 operator/(Vector2 a, Vector2 b) { return {a.x / b.x, a.y / b.y}; }
Vector2 operator*(Vector2 a, Vector2 b) { return {a.x * b.x, a.y * b.y}; }
void operator+=(Vector2 &a, Vector2 b) {
  a.x += b.x;
  a.y += b.y;
}
Vector2 operator*(Vector2 a, float b) { return {a.x * b, a.y * b}; }

Vector2 CalculateSize(float sizeToWinSizeRatio) {
  return GetWindowSize() / sizeToWinSizeRatio;
}
Vector2 CalculateSize(Vector2 sizeToWinSizeRatio) {
  return GetWindowSize() / sizeToWinSizeRatio;
}
Vector2 CalculateSpeed(float speedToWinSizeRatio) {
  return GetWindowSize() / speedToWinSizeRatio;
}
Vector2 MaintainPosAfterResize(Vector2 old, Vector2 neew, Vector2 pos) {
  return pos / old * neew;
}

Vector2 PaddleBoundaryCheck(Vector2 pos, Vector2 size) {
  if (pos.x < 0) {
    pos.x = 0;
  }
  if (pos.x > GetWindowWidth() - size.x) {
    pos.x = GetWindowWidth() - size.x;
  }
  return pos;
}

Vector2 BallBoundaryCheck(Vector2 pos, Vector2 size) {
  if (pos.x < 0) {
    pos.x = 0;
  }
  if (pos.y < 0) {
    pos.y = 0;
  }
  if (pos.x > GetWindowWidth() - size.x) {
    pos.x = GetWindowWidth() - size.x;
  }
  if (pos.y > GetWindowHeight() - size.y) {
    pos.y = GetWindowHeight() - size.y;
  }
  return pos;
}
