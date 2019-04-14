#pragma once
#include "NoobInit.h"
#include "Paddle.h"
#include "_Transform.h"
#include "Physics.h"
#include <SFML/Graphics.hpp>

class Ball: private sf::NonCopyable
{
public:
	Ball();
	~Ball();

	sf::RectangleShape mBall;
	sf::Texture mBallTexture;
	sf::Vector2f movement;

	Physics physics;
	_Transform transform;

	float BallSpeed;
	bool player1IsAlive;
	bool player2IsAlive;

	void update(sf::Time deltaTime, Paddle &mPaddle, Paddle &mPaddle2, sf::RenderWindow &mWindow, sf::Text &player1Text, sf::Text &player2Text, int &player1Lives, int &player2Lives);
	void LoadTextures();
	void setInitTransform();
	void IncreaseSpeed();
	bool player1Status();
	bool player2Status();
	void SetPlayer1Alive();
	void SetBallSpeed(float ballSpeed);
	void SetPlayer2Alive();

};

