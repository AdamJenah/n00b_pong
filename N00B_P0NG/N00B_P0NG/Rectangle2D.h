#pragma once
#include "NoobClass.h"
#include "_Transform.h"
#include "BaseComponent.h"

class Rectangle2D
{
public:
	Rectangle2D();
	~Rectangle2D();
	_Transform ObjTransform;
	sf::RectangleShape MyRect2D(float TL, float BR, float PX, float PY, float Angle, sf::Color _color);
};

