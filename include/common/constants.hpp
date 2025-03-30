#pragma once

#include <raylib.h>

namespace pong {
namespace constants {

const int WINDOW_WIDTH = 1280;
const int WINDOW_HEIGHT = 800;

const float PADDLE_WIDTH = 20.f;
const float PADDLE_HEIGHT = 100.f;
const float PADDLE_SPEED = 200.f;

const float BALL_RADIUS = 20.f;
const float BALL_SPEED = 250.f;

const Color BACKGROUND_COLOR = BLACK;
const Color PADDLE_COLOR = WHITE;
const Color BALL_COLOR = WHITE;
const Color SCORE_COLOR = WHITE;

} // namespace constants
} // namespace pong
