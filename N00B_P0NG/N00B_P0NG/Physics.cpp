#include "Physics.h"

Physics::Physics()
{
	////:Ball1(sf::Vector2f(10.0f, 10.0f))
	//{
	//	Ball1.setPosition(400.f, 10.f);//changes position of the circle
	//	Ball1.setFillColor(sf::Color::Yellow);//Sets the color of the circle
	//}

	// create function for velocity
	// create functions for other forces as needed
}
	Physics::~Physics()
	{
	}


	//void Physics::update(sf::Time elapsedTime)//update is set by time thanks to the parameters
	//{

	//	/*
	//														//movement of ball
	//		if ((Ball1.getPosition().x + (size.x / 2) > mWindow.getSize().x && increment.x > 0) ||
	//			(Ball1.getPosition().x - (size.x / 2) < 0 && increment.x < 0))
	//		{
	//			//Reverse the direction on X axis
	//			increment.x = -increment.x;
	//		}

	//		if (Ball1.getPosition().y - (size.y / 2) < 0 && increment.y < 0)
	//		{
	//			//Reverse the direction on Y axis
	//			increment.y = -increment.y;
	//		}

	//		if (Ball1.getPosition().y + (size.y / 2) > mWindow.getSize().y && increment.y > 0)
	//		{
	//			Ball1.setPosition(400.f, 10.f);
	//			Lives--;
	//		}
	//		*/
	//	Ball1.setPosition(Ball1.getPosition() + increment);

	//	//Ball and paddle hit detection
	//	//movement of ball

	//	if ((Ball1.getPosition().y + (size.y / 2) > mPlayer2.getPosition().y && increment.y > 0) &&
	//		(Ball1.getPosition().x + (size.x / 2) > mPlayer2.getPosition().x) &&
	//		(Ball1.getPosition().x + (size.x / 2) < mPlayer2.getPosition().x + 100) &&
	//		(Ball1.getPosition().y + (size.y / 2) < mPlayer2.getPosition().y + 10 && increment.y > 0))

	//	{
	//		increment.y = -increment.y;
	//		Score++;
	//	}

		//Ball1.setPosition(Ball1.getPosition() + increment);
	//}