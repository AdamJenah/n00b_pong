#include "NoobClass.h"
#include "Ball.h"
#include "Paddle.h"
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
	void updateStatistics(sf::Time elapsedTime);//Needed to update the statistics
	void updateUI(sf::Time elapsedTime);



private:
	Ball mBall;
	Paddle mPlayer1;
	Paddle mPlayer2;

	sf::Texture mBackground;
	sf::Texture mGameBackground;
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

	bool splash;
	bool menu;

	float timer;
	static const sf::Time FrameTime;//Initializes frame time

	int Score;
	int Lives1;
	int Lives2;

	//sf::Text mStatisticsText;//ADDS STATISTICS TEXT
	sf::Time mStatisticsUpdateTime;//ADDS THE FUNCTION FOR STATISTICS TO UPDATE
	std::size_t	mStatisticsNumFrames;
};

