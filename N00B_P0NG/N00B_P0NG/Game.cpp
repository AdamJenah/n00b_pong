#include "Game.h"
#include "Ball.h"
#include "Paddle.h"
#include <SFML/Window.hpp>


const sf::Time Game::FrameTime = sf::seconds(1.0f / 60.f);//Sets it to 60 frames per second after initialized in hpp.

Game::Game()
#pragma region Step2
	: mWindow(sf::VideoMode(800, 700), "N00B P0NG", sf::Style::Close)
	, mTexture()
	, mBackground()
	, Ball(sf::Vector2f(15.0f, 15.0f))
	, mPlayer2(sf::Vector2f(25.0f, 100.0f))
	, mPlayer1(sf::Vector2f(25.0f, 100.0f))
	, splashscreen(sf::Vector2f(25.0f, 100.0f))
	, splashText()
	, splash(false)
	, timer(5)
	, mIsMovingLeft(false)
	, mIsMovingRight(false)
	, increment(3.0f, 3.0f)
	, Score(0)
	, Lives(3)
	, PlayerSpeed(300.0f)
	, PlayerSpeed2(300.0f)
	, MenuSound()
	, GameSound()
#pragma endregion

{
	
	if (!MenuSound.loadFromFile("$(SolutionDir)\Assets\MenuGroove.mp3"))//fix paths
	{
		// error...
	}
	else
	{
		SoundBuffer.setBuffer(MenuSound);
	}
	if (!GameSound.loadFromFile("Desktop\n00b_pong\Assets\SpaceGroove.mp3"))
	{
		// error...
	}
	else
	{
		SoundBuffer2.setBuffer(GameSound);
	}
	SoundBuffer.setLoop(true);
	SoundBuffer.play();

	Ball.setPosition(0.f, 10.f);//changes position of the circle
	Ball.setFillColor(sf::Color::Red);//Sets the color of the circle


	//SETS TEXT
	/*if (!mFont.loadFromFile("Media/STENCIL.ttf")) return;//REQUIRED TO SET TEXT BY LOADING THE FONT
	mText.setFont(mFont);//Set the font
	mText.setString("HelloWorld");//Set the words in the text
	mText.setPosition(700, 0);//Set the Position of the text
	mText.setCharacterSize(20);//Set the size of the text
	mText.setFillColor(sf::Color::Red);//Set the color of the text

	mStatisticsText.setFont(mFont);//Set the font
	mStatisticsText.setPosition(0, 0);//Set the Position of the text
	mStatisticsText.setCharacterSize(20);//Set the size of the text
	mStatisticsText.setFillColor(sf::Color::Red);//Set the color of the text
	mStatisticsText.setString("Frame Rate");
	*/

	/*
	//SETS PROGRAM ICON AS AN IMAGE
	if (!mIcon.loadFromFile("icon.png")) return;//REQUIRED TO SET PROGRAM ICON BY LOADING THE IMAGE
	mWindow.setIcon(mIcon.getSize().x, mIcon.getSize().y, mIcon.getPixelsPtr());//Set the icon size by getting the x and y values.

	*/
#pragma region Step3
	mPlayer2.setPosition(775.0f, 0.f);
	mPlayer2.setScale(.5, 1);
	mPlayer1.setPosition(25.0f, 0.f);
	mPlayer1.setScale(.5, 1);
	splashscreen.setScale(mWindow.getSize().x, mWindow.getSize().y);
	splashscreen.setPosition(0, 0);
	splashscreen.setFillColor(sf::Color::Cyan);
	splashText.setString("Splash Screen");
	splashText.setCharacterSize(40);
	splashText.setFillColor(sf::Color::Black);
	splashText.setPosition(mWindow.getSize().x / 2, mWindow.getSize().y / 2);
	/*
	if (!mTexture.loadFromFile("background.jpg"))
		return;
	mTexture.setRepeated(true);
	mBackground.setTexture(mTexture);
	// Define a rectangle, located at (0, 0) with a size of 800X600
	//Comment out the following section to see the difference
	mBackground.setTextureRect(sf::IntRect(0, 0, 1200, 700));
	*/

#pragma endregion
}

void Game::run()
{
	sf::Clock clock;//Create Clock Variable
	sf::Time timeSinceLastUpdate = sf::Time::Zero;
	while (mWindow.isOpen())
	{
		sf::Time elapsedTime = clock.restart();//gets delta time
		timeSinceLastUpdate += elapsedTime;
		while (timeSinceLastUpdate > FrameTime)
		{

			timeSinceLastUpdate -= FrameTime;
			processEvents();
			update(FrameTime);//makes the update into per second insead of per frame
		}
		updateStatistics(elapsedTime);
		updateUI(elapsedTime);
		render();
	}
}

void Game::processEvents()
{
	sf::Event event;
	while (mWindow.pollEvent(event))
	{
		switch (event.type)
		{
		case sf::Event::Closed:
			mWindow.close();
			break;
			//KEYBOARD PRESSED AND RELEASED EVENTS INITIALIZE
		case sf::Event::KeyPressed:
			handlePlayerInput(event.key.code, true);
			break;
		case sf::Event::KeyReleased:
			handlePlayerInput(event.key.code, false);
			break;
		}
	}
}

//ACTUAL LOCATION TO DECIDE WHAT KEY DOES WHAT
void Game::handlePlayerInput(sf::Keyboard::Key key, bool isPressed) {

	if (isPressed)//For when pressed
	{
		if (key == sf::Keyboard::Up) mIsMovingLeft = true;
		else if (key == sf::Keyboard::Down) mIsMovingRight = true;
		if (key == sf::Keyboard::W) mIsMovingUp = true;
		else if (key == sf::Keyboard::S) mIsMovingDown = true;
	}

	if (!isPressed)//For when not pressed
	{
		if (key == sf::Keyboard::Up) mIsMovingLeft = false;
		else if (key == sf::Keyboard::Down) mIsMovingRight = false;
		if (key == sf::Keyboard::W) mIsMovingUp = false;
		else if (key == sf::Keyboard::S) mIsMovingDown = false;
	}
}

void Game::update(sf::Time elapsedTime)//update is set by time thanks to the parameters
{
	if (splash == false)
	{
		if (timer > 0)
		{
			timer -= elapsedTime.asSeconds();
		}
		else
		{
			SoundBuffer.stop();
			SoundBuffer2.setLoop(true);
			SoundBuffer2.play();
			splash = true;
		}
	}
	else
	{
		sf::Vector2f movement(0.f, 0.f);
		sf::Vector2f movement2(0.f, 0.f);//Adds movement per frame(required for player movement)
		if (mIsMovingLeft) movement.y -= PlayerSpeed;//The speed that the plane moves left
		if (mIsMovingRight)movement.y += PlayerSpeed;//The speed that the plane moves Right
		if (mIsMovingUp) movement2.y -= PlayerSpeed2;//The speed that the plane moves left
		if (mIsMovingDown)movement2.y += PlayerSpeed2;
		mPlayer2.move(movement*elapsedTime.asSeconds());//Setting the actual object to be moved
		mPlayer1.move(movement2*elapsedTime.asSeconds());//Setting the actual object to be moved

		if (mPlayer2.getPosition().y > 600)
		{
			PlayerSpeed = -PlayerSpeed;
			mPlayer2.setPosition(775.0f, 604);
		}
		else if (mPlayer2.getPosition().y < 600 && mPlayer2.getPosition().y>0)
		{
			PlayerSpeed = 300.0f;
		}
		else if (mPlayer2.getPosition().y < 0)
		{
			PlayerSpeed = -PlayerSpeed;
			mPlayer2.setPosition(775.0f, -4);
		}

		if (mPlayer1.getPosition().y > 600)
		{
			PlayerSpeed2 = -PlayerSpeed2;
			mPlayer1.setPosition(25.0f, 604);
		}
		else if (mPlayer1.getPosition().y < 600 && mPlayer1.getPosition().y>0)
		{
			PlayerSpeed2 = 300.0f;
		}
		else if (mPlayer1.getPosition().y < 0)
		{
			PlayerSpeed2 = -PlayerSpeed2;
			mPlayer1.setPosition(25.0f, -4);
		}


		//movement of ball
		if ((Ball.getPosition().y + (size.y / 2) > mWindow.getSize().y && increment.y > 0) ||
			(Ball.getPosition().y - (size.y / 2) < 0 && increment.y < 0))
		{
			//Reverse the direction on X axis
			increment.y = -increment.y;
		}

		if (Ball.getPosition().x - (size.x / 2) < 0 && increment.x < 0)
		{
			Ball.setPosition(400.f, 10.f);
			Lives--;
		}

		if (Ball.getPosition().x + (size.x / 2) > mWindow.getSize().x && increment.x > 0)
		{
			Ball.setPosition(400.f, 10.f);
			Lives--;
		}

		Ball.setPosition(Ball.getPosition() + increment);

		//Ball and paddle hit detection
		//movement of ball

		if ((Ball.getPosition().x + (size.x) > mPlayer2.getPosition().x && increment.x > 0) &&
			(Ball.getPosition().y + (size.y) > mPlayer2.getPosition().y) &&
			(Ball.getPosition().y + (size.y) < mPlayer2.getPosition().y + 100) &&
			(Ball.getPosition().x + (size.x) < mPlayer2.getPosition().x + 10 && increment.x > 0))

		{
			increment.x = (increment.x * -1);
			Score++;
		}

		if ((Ball.getPosition().x + (size.x) > mPlayer1.getPosition().x && increment.x < 0) &&
			(Ball.getPosition().y + (size.y) > mPlayer1.getPosition().y) &&
			(Ball.getPosition().y + (size.y) < mPlayer1.getPosition().y + 100) &&
			(Ball.getPosition().x + (size.x) < mPlayer1.getPosition().x + 10 && increment.x < 0))

		{
			increment.x = (increment.x * -1);
			Score++;
		}

		Ball.setPosition(Ball.getPosition() + increment);
	}
}

void Game::render()
{
	mWindow.clear();

#pragma region Step4
//	mWindow.draw(mText);//Actually draws the text
	if (splash == false)
	{
		mWindow.draw(splashText);
		mWindow.draw(splashscreen);
	}
	else
	{
		mWindow.draw(mPlayer2);
		mWindow.draw(mPlayer1);
		mWindow.draw(Ball);
	}
	mWindow.display();

//	mWindow.draw(mStatisticsText);
#pragma endregion

}

void Game::updateStatistics(sf::Time elapsedTime)
{
	mStatisticsUpdateTime += elapsedTime;
	mStatisticsNumFrames += 1;

	if (mStatisticsUpdateTime >= sf::seconds(1.0f))
	{
		//mStatisticsText.setString(
			//"Frames/Second = " + toString(mStatisticsNumFrames)
			//+ "\n" +
			//"Time / Update = " +
			//toString(mStatisticsUpdateTime.asMicroseconds()
			//	/ mStatisticsNumFrames) + "us");

		mStatisticsUpdateTime -= sf::seconds(1.0f);
		mStatisticsNumFrames = 0;
	}

}

void Game::updateUI(sf::Time elapsedTime)
{
	/*if (Lives > -2) {
		mText.setString(
			"Score:" + toString(Score)
			+ "\n" +
			"Lives" + toString(Lives));
		if (Lives == 0)
		{
			Lives = 3;
			Score = 0;

		}

	}*/

}
