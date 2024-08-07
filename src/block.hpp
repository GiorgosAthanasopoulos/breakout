#pragma once

#include <raylib.h>
class Block {
public:
  Block(Vector2 pos);
  void Resize(Vector2 old, Vector2 neew);
  void Update();
  void Draw();
  ~Block();

  Rectangle GetRec();

private:
  Vector2 pos, size;
};
