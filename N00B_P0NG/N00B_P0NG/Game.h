#include "NoobClass.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>//Required for audio

#pragma once
class Game
{
public:
	Game();
	void run();


private:
	void processEvents();
	void update(sf::Time deltaTime);
	void render();
	void handlePlayerInput(sf::Keyboard::Key key, bool isPressed);//Makes program handle player inputs
	void updateStatistics(sf::Time elapsedTime);//Needed to update the statistics
	void updateUI(sf::Time elapsedTime);



private:


	sf::RectangleShape mBall;
	sf::Texture mBackground;
	sf::Texture mGameBackground;
	sf::Texture mPaddle;
	sf::Texture mBallTexture;
	sf::RectangleShape mPlayer1;
	sf::RectangleShape mPlayer2;
	sf::RectangleShape splashscreen;
	sf::RectangleShape Gamescreen;
	sf::Text splashText;
	sf::Text Player1Text;
	sf::Text Player2Text;
	sf::Font font;
	sf::SoundBuffer MenuSound;
	sf::SoundBuffer GameSound;
	sf::Sound SoundBuffer;
	sf::Sound SoundBuffer2;
	sf::RenderWindow mWindow;

	//sf::Font mFont;//required to type out text 
	//sf::Text mText;//again required to initiallize text

	sf::Image mIcon;//Used to set the icon of our window to something

	sf::Vector2u size;
	sf::Vector2f increment;

	//Required for moving all directions.
	bool mIsMovingUp;
	bool mIsMovingDown;
	bool mIsMovingRight;
	bool mIsMovingLeft;
	bool splash;

	float PlayerSpeed;//Initializes PlayerSpeed
	float PlayerSpeed2;
	float timer;
	static const sf::Time FrameTime;//Initializes frame time

	int Score;
	int Lives1;
	int Lives2;

	//sf::Text mStatisticsText;//ADDS STATISTICS TEXT
	sf::Time mStatisticsUpdateTime;//ADDS THE FUNCTION FOR STATISTICS TO UPDATE
	std::size_t	mStatisticsNumFrames;
};

