#include "game/paddle.hpp"
#include "common/constants.hpp"
#include <raylib.h>

using namespace pong;
	
Paddle::Paddle(Vector2 p, float width, float height)
	: position(p),
		width(width),
		height(height)
{}

void Paddle::update(float deltaTime) {}

void Paddle::draw() {
	DrawRectangleRec(Rectangle{position.x, position.y, width, height}, constants::PADDLE_COLOR);
}
