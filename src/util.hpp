#pragma once

#include <raylib.h>

float GetWindowWidth();
float GetWindowHeight();
Vector2 GetWindowSize();

Vector2 operator/(Vector2 a, float b);
Vector2 operator/(Vector2 a, Vector2 b);
Vector2 operator*(Vector2 a, Vector2 b);
void operator+=(Vector2 &a, Vector2 b);
Vector2 operator*(Vector2 a, float b);

Vector2 CalculateSize(float sizeToWinSizeRatio);
Vector2 CalculateSize(Vector2 sizeToWinSizeRatio);
Vector2 CalculateSpeed(float speedToWinSizeRatio);
Vector2 MaintainPosAfterResize(Vector2 old, Vector2 neew, Vector2 pos);

Vector2 PaddleBoundaryCheck(Vector2 pos, Vector2 size);
Vector2 BallBoundaryCheck(Vector2 pos, Vector2 size);
