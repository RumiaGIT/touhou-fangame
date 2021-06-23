#include "stdafx.h"
#include "Reimu.h"

Reimu::Reimu()
{
	if (!texture.loadFromFile("Images/Reimu.png")) {
		std::cout << "Error loading player textures";
	}

	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 5; ++j) {
			FrameXY coord;
			coord.x = (64 + (32 * j));
			coord.y = 0 + (48 * i);

			frames[i][j] = coord;
		}
	}

	frame = 0;
	direction = 0;
	attackSpeed = 0.5;

	sprite.setTexture(texture);
	sprite.setTextureRect(sf::IntRect(0, 0, 32, 48));

	speed = 500.f;

	circle.setPosition(380, 650);
	circle.setRadius(5.f);

	circle.setFillColor(sf::Color::Cyan);
	circle.setOrigin(circle.getGlobalBounds().width / 2, circle.getGlobalBounds().height / 2);
}


Reimu::~Reimu()
{
}

float Reimu::getSpeed() {
	return speed;
}

double Reimu::getAttackspeed() {
	return attackSpeed;
}

sf::Time Reimu::getAttackCooldown() {
	return attackClock.getElapsedTime();
}

void Reimu::resetAttackCooldown() {
	attackClock.restart();
}

void Reimu::setSpeed(bool shift) {
	if (shift)
		speed = 150.f;
	else
		speed = 500.f;
}

void Reimu::updateReimu() {
	frameChange = frameChangeClock.getElapsedTime();
	if (frameChange.asSeconds() > 0.1) {
		if (frame == 4) {
			frame = 0;
		}
		else {
			++frame;
		}

		frameChangeClock.restart();
	}

	sprite.setTextureRect(sf::IntRect(*&frames[direction][frame].x, *&frames[direction][frame].y, 32, 48));
	sprite.setPosition(circle.getPosition().x - sprite.getGlobalBounds().width / 2, circle.getPosition().y - sprite.getGlobalBounds().height / 2);
}

void Reimu::updateMovement(sf::Vector2f *movement, sf::Time *deltaTime) {
	circle.move(*movement * deltaTime->asSeconds());

	if (movement->x < 0)
		direction = 1;
	else if (movement->x > 0)
		direction = 2;
	else
		direction = 0;
}