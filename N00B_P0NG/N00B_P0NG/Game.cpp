#include "Game.h"
#include "Ball.h"
#include "Paddle.h"
#include "Audio.h"
#include "Menu.h"
#include <SFML/Window.hpp>


const sf::Time Game::FrameTime = sf::seconds(1.0f / 60.f);//Sets it to 60 frames per second after initialized in hpp.

Game::Game()
	: mWindow(sf::VideoMode(800, 700), "N00B P0NG", sf::Style::Close)
	, mGameBackground()
	, mBackground()
	, splashscreen(sf::Vector2f(25.0f, 100.0f))
	, Gamescreen(sf::Vector2f(25.0f, 100.0f))
	, splashText()
	, splash(false)
	, timer(1)
	, Score(0)
	, Lives1(3)
	, Lives2(3)
	, MenuSound()
	, GameSound()
	, Player1Text()
	, Player2Text()
	, mPlayer1(25.0f, 0.f, "1")
	, mPlayer2(750.0f, 0.f, "2")

{


	Audio::PlayMusic("SpaceGroove.wav");


	//------------------------------------------------------------


	if (!font.loadFromFile("Assets/ArialCE.ttf"))
	{
		std::cout << "Failed to Load" << std::endl;
	}
	else
	{
		splashText.setFont(font);
		Player1Text.setFont(font);
		Player2Text.setFont(font);
	}


	if (!mBackground.loadFromFile("Assets/background.jpg"))
	{
		std::cout << "Failed to Load" << std::endl;
	}
	else
	{
		splashscreen.setTexture(&mBackground, false);
		mBackground.setRepeated(true);
	}
	if (!mGameBackground.loadFromFile("Assets/Gamebackground.jpg"))
	{
		std::cout << "Failed to Load" << std::endl;
	}
	else
	{
		Gamescreen.setTexture(&mGameBackground, false);
		mGameBackground.setRepeated(true);
	}


	//------------------------------------------------------------

	splashscreen.setSize(sf::Vector2f(mWindow.getSize().x, mWindow.getSize().y));
	splashscreen.setPosition(0, 0);
	Gamescreen.setSize(sf::Vector2f(mWindow.getSize().x, mWindow.getSize().y));
	Gamescreen.setPosition(0, 0);
	splashText.setString("Splash Screen");
	splashText.setCharacterSize(30);
	splashText.setFillColor(sf::Color::Red);
	splashText.setPosition((mWindow.getSize().x / 2) - 90, mWindow.getSize().y - 90 / 2);
	Player1Text.setString("Player 1 Lives: " + std::to_string(Lives1));
	Player1Text.setCharacterSize(20);
	Player1Text.setFillColor(sf::Color::Red);
	Player1Text.setPosition(10, 10);
	Player2Text.setString("Player 2 Lives: " + std::to_string(Lives2));
	Player2Text.setCharacterSize(20);
	Player2Text.setFillColor(sf::Color::Red);
	Player2Text.setPosition(mWindow.getSize().x - 180, 10);
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
			mPlayer1.handlePlayerInput(event.key.code, true);
			mPlayer2.handlePlayerInput(event.key.code, true);
			break;
		case sf::Event::KeyReleased:
			mPlayer1.handlePlayerInput(event.key.code, false);
			mPlayer2.handlePlayerInput(event.key.code, false);
			break;
		}
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
			mBall.SetPlayer1Alive();
			mBall.SetPlayer2Alive();
			Lives1 = 3;
			Lives2 = 3;
			splash = true;

		}


	}
	else
	{
		mBall.update(elapsedTime, mPlayer1, mPlayer2, mWindow, Player1Text, Player2Text, Lives1, Lives2);
		mPlayer1.update(elapsedTime, mWindow);
		mPlayer2.update(elapsedTime, mWindow);
		
		
		if (mBall.player1Status() == false) {
			timer = 3;
			splash = false;

		}

		if (mBall.player2Status() == false) {
			timer = 3;
			splash = false;
		}
	}
}

void Game::render()
{
	mWindow.clear();

	if (splash == false)
	{

		mWindow.draw(splashscreen);
		mWindow.draw(splashText);
	}
	else
	{
		mWindow.draw(Gamescreen);
		mWindow.draw(mPlayer1.mPlayer);
		mWindow.draw(mPlayer2.mPlayer);
		mWindow.draw(mBall.mBall);
		mWindow.draw(Player1Text);
		mWindow.draw(Player2Text);
	}
	mWindow.display();
}



//void Game::render()
//{
//	mWindow.clear();
//
//	if (splash == false)
//	{
//		mWindow.draw(splashscreen);
//		mWindow.draw(splashText);
//
//	}
//	else
//	{
//		Menu menu(mWindow.getSize().x, mWindow.getSize().y);
//
//		while (mWindow.isOpen())
//		{
//			sf::Event event;
//
//			while (mWindow.pollEvent(event))
//			{
//				switch (event.type)
//				{
//				case sf::Event::KeyReleased:
//					switch (event.key.code)
//					{
//					case sf::Keyboard::Up:
//						menu.MoveUp();
//						break;
//
//					case sf::Keyboard::Down:
//						menu.MoveDown();
//						break;
//
//					case sf::Keyboard::Return:
//						switch (menu.GetPressedItem())
//						{
//						case 0:
//							mWindow.draw(Gamescreen);
//							mWindow.draw(mPlayer1.mPlayer);
//							mWindow.draw(mPlayer2.mPlayer);
//							mWindow.draw(mBall.mBall);
//							mWindow.draw(Player1Text);
//							mWindow.draw(Player2Text);
//							std::cout << "Play button has been pressed" << std::endl;
//
//							break;
//						case 1:
//							std::cout << "Option button has been pressed" << std::endl;
//							break;
//						case 2:
//							mWindow.close();
//							break;
//						}
//
//						break;
//					}
//
//					break;
//				case sf::Event::Closed:
//					mWindow.close();
//
//					break;
//
//				}
//			}
//
//			mWindow.clear();
//
//			menu.draw(mWindow);
//
//			mWindow.display();
//		}
//		
//	}
//}



void Game::updateStatistics(sf::Time elapsedTime)
{
	mStatisticsUpdateTime += elapsedTime;
	mStatisticsNumFrames += 1;

	if (mStatisticsUpdateTime >= sf::seconds(1.0f))
	{
		mStatisticsUpdateTime -= sf::seconds(1.0f);
		mStatisticsNumFrames = 0;
	}

}

void Game::updateUI(sf::Time elapsedTime)
{
	//add timer

}
