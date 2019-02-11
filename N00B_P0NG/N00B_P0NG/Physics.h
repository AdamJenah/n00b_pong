#pragma once
#include "NoobClass.h"

class Physics
{
public:
	Physics();
	~Physics();

	// Define velocity()
	// Define other forces as needed

private:
	sf::RectangleShape    Ball1;
	sf::RectangleShape mPlayer2;
	sf::Vector2u size;
	sf::RenderWindow mWindow;

	sf::Vector2f increment;

	int Score;
	int Lives;
	void update(sf::Time deltaTime);
};

