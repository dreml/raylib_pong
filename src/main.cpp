#include "raylib.h"
#include "common/constants.hpp"
#include "game/game.hpp"
#include "game/audio_manager.hpp"

int main (void) {
	float screenWidth = pong::constants::WINDOW_WIDTH;
	float screenHeight = pong::constants::WINDOW_HEIGHT;

	SetConfigFlags(FLAG_MSAA_4X_HINT);

	InitWindow(screenWidth, screenHeight, "Pong");
	InitAudioDevice();

	SetTargetFPS(60);

	Music bgMusic = LoadMusicStream("assets/background_music.wav");
	Sound pongSfx = LoadSound("assets/pong_sfx.wav");
	Sound scoreSfx = LoadSound("assets/score_sfx.wav");
	pong::AudioManager audioManager{bgMusic, pongSfx, scoreSfx};

	pong::Game game{pong::ScreenDimensions{screenWidth, screenHeight}, audioManager};

	while (!WindowShouldClose()) {
		game.update(GetFrameTime());

		BeginDrawing();

		ClearBackground(BLACK);

		game.draw();

		EndDrawing();
	}

	UnloadMusicStream(bgMusic);
	CloseAudioDevice();
	CloseWindow();

	return 0;
}
