#pragma once
#include "NoobClass.h"
#include <cmath>

class Physics
{
public:
	Physics();
	~Physics();

	void update(sf::Time deltaTime, sf::Shape &Object1, sf::Shape &Object2, sf::RenderWindow &mWindow);
	sf::Vector2f Distance(sf::Vector2f pos1, sf::Vector2f pos2);
	bool Distance(sf::Vector2f pos1, sf::Vector2f pos2, float Gap);
};

