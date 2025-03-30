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
			screenDimensions,
			constants::PADDLE_WIDTH, 
			constants::PADDLE_HEIGHT,
			constants::PADDLE_SPEED,
			true
		),
		paddleRight(
			screenDimensions,
			constants::PADDLE_WIDTH,
			constants::PADDLE_HEIGHT,
			constants::PADDLE_SPEED,
			false
		),
		screenDimensions(screenDimensions)
{
	ball.setOnScoreCallback([this](bool isLeftPlayer) {
		isLeftPlayer ? leftPlayerScore++ : rightPlayerScore++;
		ball.reset();
	});
} 

void Game::update(float deltaTime) {
	paddleLeft.update(deltaTime);
	paddleRight.update(deltaTime);
	ball.update(deltaTime);

	checkCollisions();
}

void Game::draw() {
	drawField();

	paddleLeft.draw();
	paddleRight.draw();
	ball.draw();

	drawScore();
}

void Game::checkCollisions() {
	if (ball.checkPaddleCollision(paddleLeft)) {
		ball.handlePaddleCollision();
	}

	if (ball.checkPaddleCollision(paddleRight)) {
		ball.handlePaddleCollision();
	}
}

void Game::drawField() {
	DrawRectangleRec(Rectangle{0.f, 0.f, screenDimensions.width, screenDimensions.height}, constants::BACKGROUND_COLOR);
	DrawRectangleRec(Rectangle{0.f, 0.f, screenDimensions.width/2, screenDimensions.height}, constants::SECONDARY_BACKGROUND_COLOR);
	DrawCircle(screenDimensions.width/2, screenDimensions.height/2, constants::CENTER_CIRCLE_RADIUS, constants::CENTER_CIRCLE_COLOR);
	DrawLine(screenDimensions.width/2, 0, screenDimensions.width/2, screenDimensions.height, constants::CENTER_LINE_COLOR);

}

void Game::drawScore() {
	DrawText(
		TextFormat("%d", leftPlayerScore), 
		screenDimensions.width / 4 - 10, 
		10, 
		50, 
		constants::SCORE_COLOR
	);
	
	DrawText(
		TextFormat("%d", rightPlayerScore), 
		screenDimensions.width * 3 / 4- 10, 
		10, 
		50, 
		constants::SCORE_COLOR
	);
}
