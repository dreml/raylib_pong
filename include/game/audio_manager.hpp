#pragma once

#include <raylib.h>

namespace pong {

class AudioManager {
  Music bgMusic;
  Sound pongSfx;
  Sound scoreSfx;

public:
  AudioManager(const Music &bgMusic, const Sound &pongSfx,
               const Sound &scoreSfx);
  void update(float dt);
  ~AudioManager();

  void playPongSfx() const;
  void playScoreSfx() const;
};

} // namespace pong
