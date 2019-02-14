#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>//Required for audio




class Paddle

{
public:
	Paddle();
	~Paddle();
private:
	sf::RectangleShape Ball;

	sf::RectangleShape mPlayer2;

	void handlePlayerInput(sf::Keyboard::Key key, bool isPressed);//Makes program handle player inputs
	void update(sf::Time deltaTime);

	float PlayerSpeed;//Initializes PlayerSpeed

	bool mIsMovingUp;
	bool mIsMovingDown;
	bool mIsMovingRight;
	bool mIsMovingLeft;
};

