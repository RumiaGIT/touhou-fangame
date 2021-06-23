#pragma once
#ifndef BULLET_H
#define BULLET_H

#include <SFML\Graphics.hpp>

#include "Entity.h"

class Bullet : public Entity
{
public:
	Bullet();
	~Bullet();

	bool checkActive();
	void toggleActive();

	void declareBullet(sf::Vector2f , int, float);
	void updateBullet(sf::Time);

private:
	bool isActive;
	sf::Vector2f movement;
};

#endif // !BULLET_H