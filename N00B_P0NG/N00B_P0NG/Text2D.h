#pragma once
#include "NoobClass.h"
#include "_Transform.h"
#include "BaseComponent.h"

class Text2D
{
public:
	Text2D();
	~Text2D();
	_Transform ObjTransform;
	sf::Text MyText2D(sf::String message, float size, float PX, float PY, float Angle, sf::String _style, sf::Color _color);
};

