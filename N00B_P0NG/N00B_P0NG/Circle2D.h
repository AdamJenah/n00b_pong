#pragma once
#include "NoobClass.h"
#include "_Transform.h"
#include "BaseComponent.h"

class Circle2D
{
public:
	Circle2D();
	~Circle2D();
	_Transform ObjTransform;
	sf::CircleShape MyCircle2D(float Radius, float PX, float PY, float Angle, sf::Color _color);
};

