#pragma once

#include <raylib.h>

namespace pong {
namespace constants {

constexpr int WINDOW_WIDTH = 1280;
constexpr int WINDOW_HEIGHT = 800;

constexpr float PADDLE_WIDTH = 20.f;
constexpr float PADDLE_HEIGHT = 100.f;
constexpr float PADDLE_SPEED = 200.f;

constexpr float BALL_RADIUS = 20.f;
constexpr float BALL_SPEED = 350.f;

constexpr Color BACKGROUND_COLOR = LIME;
constexpr Color SECONDARY_BACKGROUND_COLOR = DARKGREEN;
constexpr Color CENTER_CIRCLE_COLOR = LIGHTGRAY;
constexpr float CENTER_CIRCLE_RADIUS = 100.f;
constexpr Color CENTER_LINE_COLOR = WHITE;
constexpr Color PADDLE_COLOR = WHITE;
constexpr Color BALL_COLOR = WHITE;
constexpr Color SCORE_COLOR = WHITE;

} // namespace constants
} // namespace pong
