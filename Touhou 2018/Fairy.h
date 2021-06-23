#pragma once
#ifndef FAIRY_H
#define FAIRY_H

#include <iostream>
#include <SFML\Graphics.hpp>

#include "Entity.h"
#include "Enums.h"

class Fairy : public Entity
{
public:
	Fairy();
	~Fairy();

	void declareFairy(sf::Vector2f, int, float);
	void updateFairy(sf::Time);

private:
	sf::Vector2f movement;
	int hitPoints;
	bool isAlive;
	struct FrameXY { int x; int y; };
	FrameXY frames[3][4];

	int frame;
	int direction;
	sf::Clock frameChangeClock;
	sf::Time frameChange;
};

#endif FAIRY_H // !FAIRY_H