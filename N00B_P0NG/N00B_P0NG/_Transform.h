#pragma once
#include "NoobClass.h"

class _Transform
{
public:
	_Transform();
	~_Transform();
	
	sf::Transform _Matrix;
	sf::Vector2f CurPos;
	float CurRot;
	sf::Vector2f CurSca;

	sf::Transform Transform_Matrix3X3(float px, float py, float pz, float rx, float ry, float rz, float sx, float sy, float sz);
	
	sf::Transform SetPos(float PX, float PY);
	sf::Transform SetRot(float angle, float PX, float PY);
	sf::Transform SetSca(float PX, float PY);//for rect
	sf::Transform SetSca(float Radius);//for circle

	sf::Transform MoveObj2D(float PX, float PY);

	sf::Vector2f GetPos();
	float GetRot();
	sf::Vector2f GetSca();
};

