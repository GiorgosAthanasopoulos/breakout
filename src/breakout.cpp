#include "breakout.hpp"
#include "util.hpp"
#include <raylib.h>

Breakout::Breakout() {
  winSize = GetWindowSize();
  Restart();
}

bool Breakout::ShouldClose() { return WindowShouldClose(); }

void Breakout::Resize(Vector2 old, Vector2 neew) {
  paddle.Resize(old, neew);
  ball.Resize(old, neew);
  for (size_t i = 0; i < blocks.size(); ++i) {
    blocks[i].Resize(old, neew);
  }
  winSize = neew;
}

void Breakout::Update() {
  paddle.Update();
  ball.Update();
  for (size_t i = 0; i < blocks.size(); ++i) {
    blocks[i].Update();
  }
}

void Breakout::Draw() {
  paddle.Draw();
  ball.Draw();
  for (size_t i = 0; i < blocks.size(); ++i) {
    blocks[i].Draw();
  }
}

Breakout::~Breakout() {}

void Breakout::Restart() {
  paddle.Reset();
  ball.Reset();
  // TODO: regenerate blocks
}
