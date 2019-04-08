#include "Graphics.h"
#include <iostream>
#include <SFML/Graphics.hpp>

sf::Texture mBackground;
sf::Texture mGameBackground;


Graphics::Graphics()
{
}


Graphics::~Graphics()
{
}

void Graphics::Initialize()
{
	std::cout << "Graphic's System Started" << "\n";
}


void Graphics::LoadBackGround(std::string filename)
{
	/*
	if (!mBackground.loadFromFile("Assets/"+ filename))
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
	*/
}

void Graphics::LoadText(std::string filename)
{

	/*if (!font.loadFromFile("Assets/ArialCE.ttf"))
	{
		std::cout << "Failed to Load" << std::endl;
	}
	else
	{
		splashText.setFont(font);
		Player1Text.setFont(font);
		Player2Text.setFont(font);
	}
	*/
}

static void LoadSplash(std::string filename) {


}

