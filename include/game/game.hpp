#pragma once

#include "common/types.hpp"
#include "game/ball.hpp"
#include "game/paddle.hpp"
#include <memory>
#include <raylib.h>

namespace pong {

class Game {
  std::unique_ptr<Paddle> paddleLeft;
  std::unique_ptr<Paddle> paddleRight;
  std::unique_ptr<Ball> ball;

  ScreenDimensions screenDimensions;
  int leftPlayerScore = 0;
  int rightPlayerScore = 0;

  void checkCollisions();
  void drawField() const;
  void drawScore() const;

public:
  Game(const ScreenDimensions &screenDimensions);

  void update(float deltaTime);
  void draw() const;
};

} // namespace pong
