#pragma once
#ifndef GAME_H
#define GAME_H

#include <SFML\Graphics.hpp>
#include <SFML\Audio.hpp>
#include <list>

#include "Bullet.h"
#include "Reimu.h"
#include "Fairy.h"

class Game
{
public:
	Game();
	~Game();

	void run();

private:
	sf::RenderWindow gameWindow;
	sf::Time timePerFrame;

	void processEvents();
	void handleInput(sf::Keyboard::Key, bool);
	void updateCollision();
	void updateMovement(sf::Time);
	void renderGame();

	Reimu reimuHakurei;
	Fairy testFairy;
	Bullet testBullet;
	std::list<Bullet> bulletArray;
	std::list<Bullet*>::const_iterator iterB;

	bool moveUp;
	bool moveDown;
	bool moveLeft;
	bool moveRight;

	bool holdShift;
	bool holdShoot;
};

#endif // !GAME_H