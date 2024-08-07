#include "block.hpp"
#include "config.hpp"
#include "util.hpp"
#include <raylib.h>

Block::Block(Vector2 pos) {
  this->pos = pos;
  Resize(GetWindowSize(), GetWindowSize());
}

void Block::Resize(Vector2 old, Vector2 neew) {
  size = CalculateSize(BLOCK_SIZE_RATIO);
  pos = MaintainPosAfterResize(old, neew, pos);
}

void Block::Update() {}

void Block::Draw() { DrawRectangleV(pos, size, BLOCK_COLOR); }

Block::~Block() {}

Rectangle Block::GetRec() { return {pos.x, pos.y, size.x, size.y}; }
