#include "pch.h"
#include "Audio.h"
#include <iostream>

sf::Music Audio::music;
sf::Sound Audio::sound;

Audio::Audio()
{
}

Audio::~Audio()
{
}

void Audio::Initialize()
{
	std::cout << "Audio Started" << "\n";
}


void Audio::PlayMusic(std::string filename)
{
	if (!music.openFromFile("Assets/" +filename))
	{
		printf("AUDIO Not Found\n");
		return;
	}
	music.setVolume(50.0f);
	music.play();
	music.setLoop(true);
}

void Audio::StopMusic()
{
	music.stop();
}