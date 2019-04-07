#pragma once
#include "NoobInit.h"
#include "_Transform.h"
#include "Physics.h"
#include <SFML/Graphics.hpp>

class Paddle
{
public:
	Paddle(float px, float py, std::string _Tag);
	~Paddle();

	sf::Texture mPaddleTexture;
	sf::RectangleShape mPlayer;
	sf::Vector2f movement;
	std::string Tag;

	_Transform transform;

	float PlayerSpeed;

	bool mIsMovingUp;
	bool mIsMovingDown;
	bool mIsMovingW;
	bool mIsMovingS;

	void handlePlayerInput(sf::Keyboard::Key key, bool isPressed);
	void update(sf::Time deltaTime, sf::RenderWindow &mWindow);
	void CheckBoundsPlayer1(sf::Time elapsedTime, sf::RenderWindow &mWindow);
	void CheckBoundsPlayer2(sf::Time elapsedTime, sf::RenderWindow &mWindow);
	void LoadTextures();
	void setInitTransform(float px, float py);
};

