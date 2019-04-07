#include "Ball.h"

Ball::Ball()
{
	LoadTextures();
	setInitTransform();
	BallSpeed = 200.0f;
	movement = sf::Vector2f(BallSpeed, BallSpeed);
}


Ball::~Ball()
{
}

void Ball::update(sf::Time elapsedTime, Paddle &mPaddle1, Paddle &mPaddle2, sf::RenderWindow &mWindow, sf::Text &player1Text, sf::Text &player2Text, int &player1Lives, int &player2Lives)
{
	if (physics.Distance(transform.GetPos(), sf::Vector2f(mWindow.getSize())).y < transform.GetSca().y / 2
		|| physics.Distance(transform.GetPos(), sf::Vector2f(0, 0)).y < transform.GetSca().y / 2)
	{
		//Reverse the direction on Y axis
		movement.y = (movement.y * -1);
	}

	if (physics.Distance(transform.GetPos(), sf::Vector2f(0, 0)).x < transform.GetSca().x / 2)
	{
		transform.SetPos(mWindow.getSize().x / 2, transform.GetSca().y);
		mBall.setPosition(transform.GetPos());
		player1Lives--;
		player1Text.setString("Player 1 Lives: " + std::to_string(player1Lives));
	}

	if (physics.Distance(transform.GetPos(), sf::Vector2f(mWindow.getSize())).x < transform.GetSca().x / 2)
	{
		transform.SetPos(mWindow.getSize().x / 2, transform.GetSca().y);
		mBall.setPosition(transform.GetPos());
		player2Lives--;
		player2Text.setString("Player 2 Lives: " + std::to_string(player2Lives));
	}

	if (physics.Distance(transform.GetPos(), mPaddle1.transform.GetPos()).x < transform.GetSca().x &&
		(mBall.getPosition().y + (mBall.getSize().y) > mPaddle1.mPlayer.getPosition().y) &&
		(mBall.getPosition().y + (mBall.getSize().y) < mPaddle1.mPlayer.getPosition().y + 100))
	{
		movement.x = (movement.x * -1);
		//Score++;
	}

	if (physics.Distance(transform.GetPos(), mPaddle2.transform.GetPos()).x < transform.GetSca().x &&
		(mBall.getPosition().y + (mBall.getSize().y) > mPaddle2.mPlayer.getPosition().y) &&
		(mBall.getPosition().y + (mBall.getSize().y) < mPaddle2.mPlayer.getPosition().y + 100))
	{
		movement.x = (movement.x * -1);
		//Score++;
	}
	transform.MoveObj2D(mBall, movement, elapsedTime);
	transform.SetPos(mBall.getPosition().x, mBall.getPosition().y);
}

void Ball::LoadTextures()
{
	if (!mBallTexture.loadFromFile("Assets/Ball.jpg"))
	{
		std::cout << "Failed to Load" << std::endl;
	}
	else
	{
		mBall.setTexture(&mBallTexture, false);
		mBallTexture.setRepeated(true);
	}
}

void Ball::setInitTransform()
{
	transform.SetSca(20, 20);
	mBall.setSize(transform.GetSca());
	transform.SetPos(400, transform.GetSca().y);
	mBall.setPosition(transform.GetPos());
}
