#pragma once
#include "NoobClass.h"
#include "BaseComponent.h"
#include "_Transform.h"

class Sprite2D : public BaseComponent
{
public:
	Sprite2D();
	~Sprite2D();
	_Transform transform;
	void MySprite2D(float TL, float BR, float PX, float PY, float Angle, sf::Texture &_texture, sf::Color _color);
	void MySprite2D(float TL, float BR, float PX, float PY, float Angle, sf::Texture &_texture);
	sf::Sprite ThisSpriteHold;
};

