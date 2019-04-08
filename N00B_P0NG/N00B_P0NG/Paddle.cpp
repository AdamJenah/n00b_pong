#include "Paddle.h"

Paddle::Paddle(float px, float py, std::string _Tag)
{
	LoadTextures();
	setInitTransform(px, py);
	Tag = _Tag;
	PlayerSpeed = 300.0f;
	movement = sf::Vector2f(0, 0);
	mIsMovingDown = false;
	mIsMovingUp = false;
	mIsMovingW = false;
	mIsMovingS = false;
}

Paddle::~Paddle()
{
}

void Paddle::handlePlayerInput(sf::Keyboard::Key key, bool isPressed) {

	if (isPressed)//For when pressed
	{
		if (Tag == "1")//for player 1
		{
			if (key == sf::Keyboard::W) mIsMovingW = true;
			else if (key == sf::Keyboard::S) mIsMovingS = true;
		}
		else//for player 2
		{
			if (key == sf::Keyboard::Up) mIsMovingUp = true;
			else if (key == sf::Keyboard::Down) mIsMovingDown = true;
		}
	}

	if (!isPressed)//For when not pressed
	{
		if (Tag == "1")//for player 1
		{
			if (key == sf::Keyboard::W) mIsMovingW = false;
			else if (key == sf::Keyboard::S) mIsMovingS = false;
		}
		else//for player 2
		{
			if (key == sf::Keyboard::Up) mIsMovingUp = false;
			else if (key == sf::Keyboard::Down) mIsMovingDown = false;
		}
	}
}

void Paddle::update(sf::Time elapsedTime, sf::RenderWindow &mWindow)
{
	if (mIsMovingUp)
	{
		movement.y = -PlayerSpeed;
		CheckBoundsPlayer2(elapsedTime, mWindow);
	}
	if (mIsMovingDown)
	{
		movement.y = PlayerSpeed;
		CheckBoundsPlayer2(elapsedTime, mWindow);
	}

	if (mIsMovingW)
	{
		movement.y = -PlayerSpeed;
		CheckBoundsPlayer1(elapsedTime, mWindow);
	}
	if (mIsMovingS)
	{
		movement.y = PlayerSpeed;
		CheckBoundsPlayer1(elapsedTime, mWindow);
	}
}

void Paddle::CheckBoundsPlayer1(sf::Time elapsedTime, sf::RenderWindow &mWindow)
{
	if (transform.GetPos().y > mWindow.getSize().y - transform.GetSca().y)
	{
		transform.SetPos(25.0f, mWindow.getSize().y - transform.GetSca().y);
		mPlayer.setPosition(transform.CurPos);
	}
	else if (transform.GetPos().y <= mWindow.getSize().y - transform.GetSca().y && transform.GetPos().y >= 0)
	{
		transform.MoveObj2D(mPlayer, movement, elapsedTime);
		transform.SetPos(mPlayer.getPosition().x, mPlayer.getPosition().y);
	}
	else if (transform.GetPos().y < 0)
	{
		transform.SetPos(25.0f, 0);
		mPlayer.setPosition(transform.CurPos);
	}
}

void Paddle::CheckBoundsPlayer2(sf::Time elapsedTime, sf::RenderWindow &mWindow)
{
	if (transform.GetPos().y > mWindow.getSize().y - transform.GetSca().y)
	{
		transform.SetPos(750.0f, mWindow.getSize().y - transform.GetSca().y);
		mPlayer.setPosition(transform.CurPos);
	}
	else if (transform.GetPos().y <= mWindow.getSize().y - transform.GetSca().y && transform.GetPos().y >= 0)
	{
		transform.MoveObj2D(mPlayer, movement, elapsedTime);
		transform.SetPos(mPlayer.getPosition().x, mPlayer.getPosition().y);
	}
	else if (transform.GetPos().y < 0)
	{
		transform.SetPos(750.0f, 0);
		mPlayer.setPosition(transform.CurPos);
	}
}

void Paddle::LoadTextures()
{
	if (!mPaddleTexture.loadFromFile("Assets/Wood.jpg"))
	{
		std::cout << "Failed to Load" << std::endl;
	}
	else
	{
		mPlayer.setTexture(&mPaddleTexture, false);
	}
}

void Paddle::setInitTransform(float px, float py)
{
	transform.SetPos(px, py);
	mPlayer.setPosition(transform.GetPos());
	transform.SetSca(20, 100);
	mPlayer.setSize(transform.GetSca());
}
