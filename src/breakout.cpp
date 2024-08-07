#include "breakout.hpp"
#include "config.hpp"
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

  // TODO: check ball collision with paddle, window and block
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
  for (int row = 0; row < BALL_COUNT_Y; ++row) {
    for (int col = 0; col < BALL_COUNT_X; ++col) {
      Vector2 blockSize = CalculateSize(BLOCK_SIZE_RATIO);
      blocks.push_back(Block(
          {GetWindowWidth() / BLOCKS_PADDING_X +
               col * (blockSize.x + GetWindowWidth() / BLOCKS_INNER_PADDING_X),
           GetWindowHeight() / BLOCKS_PADDING_Y +
               row * (blockSize.y +
                      GetWindowHeight() / BLOCKS_INNER_PADDING_Y)}));
    }
  }
}
