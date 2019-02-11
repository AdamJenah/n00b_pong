#pragma once
#include "NoobClass.h"
#include "_Transform.h"
#include "BaseComponent.h"

class Sprite2D
{
public:
	Sprite2D();
	~Sprite2D();
	_Transform ObjTransform;
	sf::Sprite MySprite2D(float TL, float BR, float PX, float PY, float Angle, sf::Texture _texture, sf::Color _color);
};

