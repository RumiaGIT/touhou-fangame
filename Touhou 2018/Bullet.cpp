#include "stdafx.h"
#include "Bullet.h"

Bullet::Bullet()
{
	isActive = false;
	circle.setRadius(5.f);

	circle.setFillColor(sf::Color::Cyan);
	circle.setOrigin(circle.getGlobalBounds().width / 2, circle.getGlobalBounds().height / 2);
}

Bullet::~Bullet()
{
}

bool Bullet::checkActive() {
	return isActive;
}

void Bullet::toggleActive() {
	if (isActive)
		isActive = false;
	else
		isActive = true;
}

void Bullet::declareBullet(sf::Vector2f pos, int speed, float angle) {
	circle.setPosition(pos.x, pos.y);

	movement.x = speed * cos(angle);
	movement.y = speed * sin(angle);
}

void Bullet::updateBullet(sf::Time deltaTime) {
	circle.move(movement * deltaTime.asSeconds());
	sprite.setPosition(circle.getPosition().x - sprite.getGlobalBounds().width / 2, circle.getPosition().y - sprite.getGlobalBounds().height / 2);
}