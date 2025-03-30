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
const float BALL_SPEED = 350.f;

const Color BACKGROUND_COLOR = LIME;
const Color SECONDARY_BACKGROUND_COLOR = DARKGREEN;
const Color CENTER_CIRCLE_COLOR = LIGHTGRAY;
const float CENTER_CIRCLE_RADIUS = 100.f;
const Color CENTER_LINE_COLOR = WHITE;
const Color PADDLE_COLOR = WHITE;
const Color BALL_COLOR = WHITE;
const Color SCORE_COLOR = WHITE;

} // namespace constants
} // namespace pong
