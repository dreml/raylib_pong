#pragma once

#include "common/types.hpp"
#include "game/paddle.hpp"
#include <raylib.h>

namespace pong {

class Ball {
  ScreenDimensions screenDimensions;
  Vector2 defaultPosition;
  Vector2 position;
  Vector2 direction;
  float speed;
  float radius;

  Vector2 getInitialDirection();

  ScoreCallback onScoreCallback;

public:
  Ball(ScreenDimensions dimensions, float speed, float radius);

  void update(float deltaTime);
  void draw();
  void reset();
  bool checkPaddleCollision(Paddle paddle);
  void handlePaddleCollision();

  void setOnScoreCallback(ScoreCallback callback) {
    onScoreCallback = callback;
  }
};

} // namespace pong
