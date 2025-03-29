#include "game/ball.hpp"
#include "common/types.hpp"
#include "common/constants.hpp"
#include <raylib.h>

using namespace pong;
	
Ball::Ball(ScreenDimensions dimensions, float speed, float radius)
	: screenDimensions(dimensions),
		defaultPosition(Vector2{dimensions.width/2, dimensions.height/2}),
		speed(speed),
		radius(radius)
{
	reset();
}

void Ball::update(float deltaTime) {
	position.x += direction.x * speed * deltaTime;
	position.y += direction.y * speed * deltaTime;

	if (position.x <= radius || position.x >= screenDimensions.width - radius) {
		direction.x *= -1;
	}
	if (position.y <= radius || position.y >= screenDimensions.height - radius) {
		direction.y *= -1;
	}
}

void Ball::draw() {
	DrawCircle(position.x, position.y, constants::BALL_RADIUS, constants::BALL_COLOR);
}

void Ball::reset() {
	position = defaultPosition;
	direction = getInitialDirection();
}

Vector2 Ball::getInitialDirection() {
	return {1.f, 1.f};
}
