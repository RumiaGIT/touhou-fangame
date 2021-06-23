#include "stdafx.h"
#include "Game.h"

#include <iostream>

Game::Game()
	: gameWindow{sf::VideoMode(960, 720), "Test", sf::Style::Close}
	, timePerFrame(sf::seconds(1.f / 60.f))
{
	moveUp = false;
	moveDown = false;
	moveLeft = false;
	moveRight = false;
	holdShift = false;
	holdShoot = false;

	for (int i = 0; i < 50; ++i) {
		bulletArray.push_back(testBullet);
	}

	std::cout << bulletArray.size();
	testFairy.declareFairy(sf::Vector2f(50, 50), 10, 0.f);
}

Game::~Game()
{
}

void Game::run() {
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;

	sf::Clock dtClock;
	while (gameWindow.isOpen()) {
		//std::cout << "Elapsed time: " << clock.getElapsedTime().asMilliseconds() << "ms" << std::endl;
		timeSinceLastUpdate += clock.restart();
		while (timeSinceLastUpdate > timePerFrame) {
			sf::Time deltaTime = dtClock.restart();

			timeSinceLastUpdate -= timePerFrame;
			processEvents();
			updateMovement(deltaTime);
		}
		renderGame();
	}
}

void Game::processEvents() {
	sf::Event event;

	while (gameWindow.pollEvent(event)) {
		switch (event.type) {
		case sf::Event::Closed:
			gameWindow.close();
			break;

		case sf::Event::KeyPressed:
			handleInput(event.key.code, true);
			break;

		case sf::Event::KeyReleased:
			handleInput(event.key.code, false);
			break;
		}
	}
}

void Game::handleInput(sf::Keyboard::Key key, bool isPressed) {
	switch (key) {
	case sf::Keyboard::Up:
		moveUp = isPressed;
		break;

	case sf::Keyboard::Down:
		moveDown = isPressed;
		break;

	case sf::Keyboard::Left:
		moveLeft = isPressed;
		break;

	case sf::Keyboard::Right:
		moveRight = isPressed;
		break;

	case sf::Keyboard::LShift:
		holdShift = isPressed;
		break;

	case sf::Keyboard::Z:
		holdShoot = isPressed;
		break;
	}
}

void Game::updateCollision() {

}

void Game::updateMovement(sf::Time deltaTime) {
	sf::Vector2f playerMovement(0.f, 0.f);

	if (moveUp)
		playerMovement.y -= reimuHakurei.getSpeed();

	if (moveDown)
		playerMovement.y += reimuHakurei.getSpeed();

	if (moveLeft)
		playerMovement.x -= reimuHakurei.getSpeed();

	if (moveRight)
		playerMovement.x += reimuHakurei.getSpeed();

	if (holdShift)
		reimuHakurei.setSpeed(true);
	else
		reimuHakurei.setSpeed(false);

	reimuHakurei.updateMovement(&playerMovement, &deltaTime);
	reimuHakurei.updateReimu();
	testFairy.updateFairy(deltaTime);

	if (holdShoot) {
		if (reimuHakurei.getAttackCooldown().asSeconds() >= reimuHakurei.getAttackspeed()) {
			for (auto &i : bulletArray) {
				if (!i.checkActive()) {
					std::cout << "test" << std::endl;
					reimuHakurei.resetAttackCooldown();
					i.declareBullet(reimuHakurei.circle.getPosition(), 1, 0.f);
					i.toggleActive();
					return;
				}
			}
		}
	}

	for (auto &i : bulletArray) {
		if (i.checkActive()) {
			i.updateBullet(deltaTime);
		}
	}
}

void Game::renderGame() {
	gameWindow.clear();
	gameWindow.draw(reimuHakurei.sprite);
	gameWindow.draw(testFairy.sprite);
	//gameWindow.draw(testFairy.circle);

	if (holdShift)
		gameWindow.draw(reimuHakurei.circle);

	for (auto &i : bulletArray) {
		if (i.checkActive()) {
			gameWindow.draw(i.circle);
		}
	}

	gameWindow.display();
}