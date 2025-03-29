#pragma once

#include <raylib.h>

namespace pong {

class Paddle {
  float width;
  float height;
  Vector2 position;

public:
  Paddle(Vector2 p, float width, float height);

  void update(float deltaTime);
  void draw();
};

} // namespace pong
