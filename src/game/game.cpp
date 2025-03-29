#include "game/game.hpp"
#include "common/constants.hpp"
#include "common/types.hpp"
#include "game/ball.hpp"
#include "game/paddle.hpp"
#include <raylib.h>

using namespace pong;
	
Game::Game(ScreenDimensions screenDimensions) 
	: ball(screenDimensions, constants::BALL_SPEED, constants::BALL_RADIUS),
		paddleLeft(
			Vector2{10, screenDimensions.height/2 - constants::PADDLE_HEIGHT/2},
			constants::PADDLE_WIDTH, 
			constants::PADDLE_HEIGHT
		),
		paddleRight(
			Vector2{screenDimensions.width - constants::PADDLE_WIDTH - 10, screenDimensions.height/2 - constants::PADDLE_HEIGHT/2},
			constants::PADDLE_WIDTH,
			constants::PADDLE_HEIGHT
		)
{} 

void Game::update(float deltaTime) {
	paddleLeft.update(deltaTime);
	paddleRight.update(deltaTime);
	ball.update(deltaTime);
}

void Game::draw() {
	paddleLeft.draw();
	paddleRight.draw();
	ball.draw();
}
