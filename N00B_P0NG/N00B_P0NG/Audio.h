#pragma once

#include <SFML/Audio.hpp>


class Audio
{
public:
	Audio();
	~Audio();
	static void Initialize();
	static void PlayMusic(std::string filename);
	static void StopMusic();

private:
	static sf::Music music;
	static sf::Sound sound;
};