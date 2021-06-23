#include "stdafx.h"
#include "Fairy.h"

Fairy::Fairy()
{
	if (!texture.loadFromFile("Images/Enemy.png")) {
		std::cout << "Error loading enemy textures";
	}

	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 4; ++j) {
			FrameXY coord;
			coord.x = (0 + (48 * j));
			coord.y = 0 + (32 * i);

			frames[i][j] = coord;
			std::cout << coord.x << "," << coord.y << " ";
		}
		std::cout << std::endl;
	}

	isAlive = true;
	frame = 0;

	circle.setRadius(15.f);

	circle.setFillColor(sf::Color::Blue);
	circle.setOrigin(circle.getGlobalBounds().width / 2, circle.getGlobalBounds().height / 2);

	sprite.setTexture(texture);
	sprite.setTextureRect(sf::IntRect(0, 0, 48, 32));
	sprite.scale(1.25f, 1.25f);
}

Fairy::~Fairy()
{
}

void Fairy::declareFairy(sf::Vector2f pos, int speed, float angle) {
	circle.setPosition(pos.x, pos.y);
	
	movement.x = speed * cos(angle);
	movement.y = speed * sin(angle);
}

void Fairy::updateFairy(sf::Time deltaTime) {
	circle.move(movement * deltaTime.asSeconds());

	frameChange = frameChangeClock.getElapsedTime();
	if (frameChange.asSeconds() > 0.1) {
		if (frame == 3)
			frame = 0;
		else
			++frame;

		frameChangeClock.restart();
	}

	if (movement.x > 0)
		direction = 2;
	else if (movement.x < 0)
		direction = 1;
	else
		direction = 0;

	sprite.setTextureRect(sf::IntRect(frames[direction][frame].x, frames[direction][frame].y, 48, 32));
	sprite.setPosition(circle.getPosition().x - sprite.getGlobalBounds().width / 2, circle.getPosition().y - sprite.getGlobalBounds().height / 2);
}