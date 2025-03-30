#pragma once

#include <functional>

namespace pong {

struct ScreenDimensions {
  float width;
  float height;
};

using ScoreCallback = std::function<void(bool isLeftPlayer)>;

} // namespace pong
