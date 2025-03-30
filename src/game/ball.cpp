#include "game/ball.hpp"
#include "common/types.hpp"
#include "common/constants.hpp"
#include <raylib.h>

using namespace pong;
	
Ball::Ball(const ScreenDimensions &dimensions, float speed, float radius)
	: screenDimensions(dimensions),
		defaultPosition(Vector2{dimensions.width/2, dimensions.height/2}),
		speed(speed),
		radius(radius)
{
	resetBall();
}

void Ball::update(float deltaTime) {
	position.x += direction.x * speed * deltaTime;
	position.y += direction.y * speed * deltaTime;

	if (position.y <= radius || position.y >= screenDimensions.height - radius) {
		direction.y *= -1;
	}

	if (position.x <= radius || position.x >= screenDimensions.width - radius) {
		direction.x *= -1;

		onScoreCallback(position.x >= screenDimensions.width - radius);
	}
}

void Ball::draw() const {
	DrawCircle(position.x, position.y, constants::BALL_RADIUS, constants::BALL_COLOR);
}

void Ball::resetBall() {
	position = defaultPosition;
	direction = getInitialDirection();
}

Vector2 Ball::getInitialDirection() const {
	float directionVariants[2] = {-1.f, 1.f};

	return {
		directionVariants[GetRandomValue(0, 1)],
		directionVariants[GetRandomValue(0, 1)],
	};
}

bool Ball::checkPaddleCollision(Paddle &paddle) const {
	return CheckCollisionCircleRec(position, radius, paddle.getAABB());
}

void Ball::handlePaddleCollision() {
	direction.x *= -1;
}
