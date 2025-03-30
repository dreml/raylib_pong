#include "game/paddle.hpp"
#include "common/constants.hpp"
#include "common/types.hpp"
#include <algorithm>
#include <raylib.h>

using namespace pong;
	
Paddle::Paddle(ScreenDimensions screenDimensions, float width, float height, float speed, bool isLeft)
	: screenDimensions(screenDimensions),
		width(width),
		height(height),
		speed(speed),
		isLeft(isLeft)
{
	if (isLeft) {
		position = Vector2{10, screenDimensions.height/2 - height/2};
	} else {
		position = Vector2{screenDimensions.width - width - 10, screenDimensions.height/2 - height/2};
	}
}

void Paddle::update(float deltaTime) {
	if (isKeyUpPressed()) {
		position.y -= speed * deltaTime;
	}
	if (isKeyDownPressed()) {
		position.y += speed * deltaTime;
	}

	position.y = std::clamp(position.y, 0.f, screenDimensions.height - height);
}

void Paddle::draw() {
	DrawRectangleRounded(getAABB(), .8f, 0, constants::PADDLE_COLOR);
}

bool Paddle::isKeyUpPressed() {
	if (isLeft) {
		return IsKeyDown(KEY_P);
	} else {
		return IsKeyDown(KEY_L);
	}
};

bool Paddle::isKeyDownPressed() {
	if (isLeft) {
		return IsKeyDown(KEY_D);
	} else {
		return IsKeyDown(KEY_H);
	}
};

Rectangle Paddle::getAABB() {
	return {position.x, position.y, width, height};
}
