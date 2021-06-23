#pragma once
#ifndef ENTITY_H
#define ENTITY_H

#include "SFML\Graphics.hpp"

class Entity
{
public:
	Entity();
	~Entity();

	sf::CircleShape circle;
	sf::Sprite sprite;
	sf::Texture texture;
};

#endif // !ENTITY_H