#pragma once
#include "NoobClass.h"

class BaseComponent
{
public:
	BaseComponent();
	~BaseComponent();

	virtual void drawShape(sf::RenderTarget& target, sf::Sprite _sprite) const;
};

