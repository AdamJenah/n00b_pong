#pragma once

#define BOOK_GAME_HPP

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>//Required for audio


class Ball: private sf::NonCopyable
{
public:
	Ball();
	~Ball();
private:
	sf::RectangleShape	Ball1;
	sf::RectangleShape mPlayer2;
	sf::Vector2u size;
	sf::RenderWindow mWindow;

	sf::Vector2f increment;

	int Score;
	int Lives;

	void update(sf::Time deltaTime);
	
};

