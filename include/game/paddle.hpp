#pragma once

#include "common/types.hpp"
#include <raylib.h>

namespace pong {

class Paddle {
  float width;
  float height;
  Vector2 position;
  ScreenDimensions screenDimensions;
  bool isLeft;
  float speed;

  bool isKeyUpPressed() const;
  bool isKeyDownPressed() const;

public:
  Paddle(const ScreenDimensions &screenDimensions, float width, float height,
         float speed, bool isLeft);

  void update(float deltaTime);
  void draw() const;
  Rectangle getAABB() const;
};

} // namespace pong
