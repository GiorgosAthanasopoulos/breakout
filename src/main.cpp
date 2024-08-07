#include "breakout.hpp"
#include "config.hpp"
#include "raylib.hpp"
#include "util.hpp"
#include <raylib.h>
int main() {
  Raylib *r = new Raylib;
  Breakout *g = new Breakout;
  Vector2 winSize = GetWindowSize();

  while (!g->ShouldClose()) {
    if (IsWindowResized()) {
      Vector2 neew = GetWindowSize();
      g->Resize(winSize, neew);
      r->Resize(winSize, neew);
      winSize = neew;
    }

    g->Update();
    r->Update();

    BeginDrawing();
    ClearBackground(WIN_BG);
    g->Draw();
    r->Draw();
    EndDrawing();
  }

  delete g;
  delete r;
  return 0;
}
