#include "Paddle.h"



Paddle::Paddle()
{
}


Paddle::~Paddle()
{
}

void Paddle::handlePlayerInput(sf::Keyboard::Key key, bool isPressed) {

	if (isPressed)//For when pressed
	{
		if (key == sf::Keyboard::Up) mIsMovingLeft = true;
		else if (key == sf::Keyboard::Down) mIsMovingRight = true;
	}

	if (!isPressed)//For when not pressed
	{
		if (key == sf::Keyboard::Up) mIsMovingLeft = false;
		else if (key == sf::Keyboard::Down) mIsMovingRight = false;
	}
}

void Paddle::update(sf::Time elapsedTime)//update is set by time thanks to the parameters
{
	sf::Vector2f movement(0.f, 0.f);//Adds movement per frame(required for player movement)
	if (mIsMovingLeft) movement.y -= PlayerSpeed;//The speed that the plane moves left
	if (mIsMovingRight)movement.y += PlayerSpeed;//The speed that the plane moves Right
	
	mPlayer2.move(movement*elapsedTime.asSeconds());//Setting the actual object to be moved

	if (mPlayer2.getPosition().y > 700)
	{
		PlayerSpeed = -PlayerSpeed;
	}
	else if (mPlayer2.getPosition().y < 700 && mPlayer2.getPosition().y>0)
	{
		PlayerSpeed = 300.0f;
	}
	else if (mPlayer2.getPosition().y < 0)
	{
		PlayerSpeed = -PlayerSpeed;
	}

}
