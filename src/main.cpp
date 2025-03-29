#include "raylib.h"
#include "common/constants.hpp"
#include "game/game.hpp"

int main (void) {
	float screenWidth = pong::constants::WINDOW_WIDTH;
	float screenHeight = pong::constants::WINDOW_HEIGHT;

	InitWindow(screenWidth, screenHeight, "Pong");

	SetTargetFPS(60);

	pong::Game game{pong::ScreenDimensions{screenWidth, screenHeight}};

	while (!WindowShouldClose()) {
		BeginDrawing();

		ClearBackground(pong::constants::BACKGROUND_COLOR);

		game.update(GetFrameTime());
		game.draw();

		EndDrawing();
	}

	CloseWindow();

	return 0;
}
