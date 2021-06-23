#pragma once
#ifndef REIMU_H
#define REIMU_H

#include <iostream>
#include <SFML\Graphics.hpp>

#include "Entity.h"

class Reimu : public Entity
{
public:
	Reimu();
	~Reimu();

	float getSpeed();
	double getAttackspeed();
	sf::Time getAttackCooldown();
	void resetAttackCooldown();
	void setSpeed(bool);
	void updateReimu();
	void updateMovement(sf::Vector2f*, sf::Time*);

private:
	float speed;
	double attackSpeed;
	struct FrameXY { int x; int y; };
	FrameXY frames[3][5];

	int frame;
	int direction;
	sf::Clock frameChangeClock;
	sf::Time frameChange;

	sf::Clock attackClock;
	sf::Time attackCooldown;
};

#endif // !REIMU_H