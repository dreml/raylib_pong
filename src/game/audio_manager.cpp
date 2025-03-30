#include "game/audio_manager.hpp"
#include <raylib.h>

using namespace pong;

AudioManager::AudioManager(const Music &bgMusic, const Sound &pongSfx, const Sound &scoreSfx)
	: bgMusic(bgMusic),
		pongSfx(pongSfx),
		scoreSfx(scoreSfx)
{
	SetMusicVolume(bgMusic, .5f);
	SetSoundVolume(scoreSfx, .3f);

	PlayMusicStream(bgMusic);
}

AudioManager::~AudioManager() {
	UnloadMusicStream(bgMusic);
	UnloadSound(pongSfx);
}

void AudioManager::update(float dt) {
	UpdateMusicStream(bgMusic);
}

void AudioManager::playPongSfx() const {
	PlaySound(pongSfx);
}

void AudioManager::playScoreSfx() const {
	PlaySound(scoreSfx);
}
