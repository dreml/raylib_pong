#pragma once

#include "common/types.hpp"
#include "game/ball.hpp"
#include "game/paddle.hpp"
#include <raylib.h>

namespace pong {

class Game {
  Paddle paddleLeft;
  Paddle paddleRight;
  Ball ball;
  ScreenDimensions screenDimensions;
  int leftPlayerScore = 0;
  int rightPlayerScore = 0;

  void checkCollisions();
  void drawScore();

public:
  Game(ScreenDimensions screenDimensions);

  void update(float deltaTime);
  void draw();
};

} // namespace pong
