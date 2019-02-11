#pragma once
#include "NoobClass.h"
#include "BaseComponent.h"

class Objects
{
public:
	Objects();
	~Objects();

	void Update(sf::RenderWindow& _window, sf::Time elapsedTime, sf::Sprite _sprite);
};

