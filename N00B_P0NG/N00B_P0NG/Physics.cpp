#include "Physics.h"

Physics::Physics()
{
}

Physics::~Physics()
{
}

void Physics::update(sf::Time deltaTime, sf::Shape &Object1, sf::Shape &Object2, sf::RenderWindow &mWindow)
{
	//if (mBall.getPosition().x - (mBall.getSize().x / 2) < 0 && movement.x < 0)
	//{
	//	mBall.setPosition(400.f, 10.f);
	//	//Lives1--;
	//	//Player1Text.setString("Player 1 Lives: " + std::to_string(Lives1));
	//}

	//if (mBall.getPosition().x + (mBall.getSize().x / 2) > mWindow.getSize().x && movement.x > 0)
	//{
	//	mBall.setPosition(400.f, 10.f);
	//	//Lives2--;
	//	//Player2Text.setString("Player 2 Lives: " + std::to_string(Lives2));
	//}

	//if ((mBall.getPosition().x + (mBall.getSize().x) > mPaddle1.mPlayer.getPosition().x - 20 && movement.x > 0) &&
	//	(mBall.getPosition().y + (mBall.getSize().y) > mPaddle1.mPlayer.getPosition().y) &&
	//	(mBall.getPosition().y + (mBall.getSize().y) < mPaddle1.mPlayer.getPosition().y + 100) &&
	//	(mBall.getPosition().x + (mBall.getSize().x) < mPaddle1.mPlayer.getPosition().x + 10 && movement.x > 0))

	//{
	//	//increment.x = (increment.x * -1);
	//	//Score++;
	//}

	//if ((mBall.getPosition().x + (mBall.getSize().x) > mPaddle2.mPlayer.getPosition().x && movement.x < 0) &&
	//	(mBall.getPosition().y + (mBall.getSize().y) > mPaddle2.mPlayer.getPosition().y) &&
	//	(mBall.getPosition().y + (mBall.getSize().y) < mPaddle2.mPlayer.getPosition().y + 100) &&
	//	(mBall.getPosition().x + (mBall.getSize().x) < mPaddle2.mPlayer.getPosition().x + 10 && movement.x < 0))

	//{
	//	//increment.x = (increment.x * -1);
	//	//Score++;
	//}
}

sf::Vector2f Physics::Distance(sf::Vector2f pos1, sf::Vector2f pos2)
{
	return sf::Vector2f(abs(pos1.x - pos2.x), abs(pos1.y - pos2.y));
}

bool Physics::Distance(sf::Vector2f pos1, sf::Vector2f pos2, float Gap)
{
	if (abs(pos1.x - pos2.x) < Gap && abs(pos1.y - pos2.y) < Gap)
	{
		return true;
	}
	return false;
}
