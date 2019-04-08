#pragma once

#include <SFML/Graphics.hpp>

class Graphics
{
public:
	Graphics();
	~Graphics();
	static void Initialize();
	static void LoadBackGround(std::string filename);
	static void LoadText(std::string filename);
	static void LoadSplash(std::string filename);


private:
	sf::Texture mBackground;
	sf::Texture mGameBackground;
	sf::RectangleShape splashscreen;
	sf::RectangleShape Gamescreen;
	sf::Text splashText;
	sf::Text Player1Text;
	sf::Text Player2Text;
	sf::Font font;
};

