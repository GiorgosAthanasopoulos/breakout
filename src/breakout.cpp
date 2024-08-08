#include "breakout.hpp"
#include "config.hpp"
#include "util.hpp"
#include <raylib.h>
#include <sstream>
#include <string>

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
  if (lost) {
    HandleLost();
    return;
  }
  if (won) {
    HandleWon();
    return;
  }
  HandlePaused();
  if (paused) {
    return;
  }

  ball.Update();
  HandleBlocks();
  HandlePaddle();
  HandleTimers();
}

void Breakout::Draw() {
  if (lost) {
    DrawLost();
    return;
  }
  if (won) {
    DrawWon();
    return;
  }
  if (paused) {
    DrawPaused();
    return;
  }

  DrawEntities();
  DrawUI();
}

Breakout::~Breakout() {}

void Breakout::Restart() {
  paddle.Reset();
  ball.Reset();
  blocks.clear();
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
  lost = false;
  won = false;
  paused = false;
  gameTimer = GAME_TIME;
  score = 0;
}

void Breakout::HandleLost() {
  if (IsKeyPressed(KEY_RESTART)) {
    Restart();
  }
}

void Breakout::HandleWon() {
  if (IsKeyPressed(KEY_RESTART)) {
    Restart();
  }
}

void Breakout::HandlePaused() {
  if (IsKeyPressed(KEY_PAUSE_GAME)) {
    paused = !paused;
  }
}

void Breakout::HandleBlocks() {
  for (size_t i = 0; i < blocks.size(); ++i) {
    blocks[i].Update();

    if (CheckCollisionCircleRec(ball.GetPos(), ball.GetRadius(),
                                blocks[i].GetRec())) {
      ball.SetSpeed({ball.GetSpeed().x, ball.GetSpeed().y * -1});
      blocks.erase(blocks.begin() + i);
      score += SCORE_INTERVAL;
      continue;
    }
  }

  if (blocks.empty()) {
    won = true;
  }
}

void Breakout::HandlePaddle() {
  paddle.Update();
  if (CheckCollisionCircleRec(ball.GetPos(), ball.GetRadius(),
                              paddle.GetRec())) {
    ball.SetSpeed({ball.GetSpeed().x, ball.GetSpeed().y * -1});
  }
}

void Breakout::HandleTimers() {
  gameTimer -= GetFrameTime();
  if (gameTimer <= 0.0f) {
    lost = true;
  }
}

void Breakout::DrawEntities() {
  paddle.Draw();
  ball.Draw();
  for (size_t i = 0; i < blocks.size(); ++i) {
    blocks[i].Draw();
  }
}

void Breakout::DrawLost() {
  const char *text = "You lost";
  Vector2 size =
      AssertTextFitsInViewport(text, LARGE_FONT_SIZE, GetWindowSize() / 2);
  DrawText(text, GetWindowWidth() / 2 - size.x / 2,
           GetWindowHeight() / 2 - size.y / 2, size.y, UI_TEXT_COLOR);
}

void Breakout::DrawWon() {
  const char *text = "You won";
  Vector2 size =
      AssertTextFitsInViewport(text, LARGE_FONT_SIZE, GetWindowSize() / 2);
  DrawText(text, GetWindowWidth() / 2 - size.x / 2,
           GetWindowHeight() / 2 - size.y / 2, size.y, UI_TEXT_COLOR);
}

void Breakout::DrawPaused() {
  const char *text = "Paused";
  Vector2 size =
      AssertTextFitsInViewport(text, LARGE_FONT_SIZE, GetWindowSize() / 2);
  DrawText(text, GetWindowWidth() / 2 - size.x / 2,
           GetWindowHeight() / 2 - size.y / 2, size.y, UI_TEXT_COLOR);
}

void Breakout::DrawUI() {
  float timePercentage = gameTimer / GAME_TIME;
  DrawRectangle(winSize.x - TIMER_W, 0, TIMER_W, timePercentage * winSize.y,
                TIMER_COLOR);

  std::ostringstream ss;
  ss << "Score: " << score;
  std::string s = ss.str();
  const char *t = s.data();
  Vector2 sz = AssertTextFitsInViewport(t, FONT_SIZE, GetWindowSize() / 6);
  DrawText(t, 0, winSize.y - sz.y - SCORE_TEXT_PADDING, sz.y, UI_TEXT_COLOR);
}
