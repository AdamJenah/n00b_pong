#include "_Transform.h"

_Transform::_Transform()
{
}

_Transform::~_Transform()
{
}

sf::Transform _Transform::Transform_Matrix3X3(float px, float py, float pz, float rx, float ry, float rz, float sx, float sy, float sz)
{
	sf::Transform temp(px, py, pz, rx, ry, rz, sx, sy, sz);
	_Matrix = temp;
	return _Matrix;
};

sf::Transform _Transform::SetPos(float px, float py)
{
	CurPos = sf::Vector2f(px, py);
	sf::Transform temp;
	return temp.translate(px, py);
}

sf::Transform _Transform::SetRot(float angle, float px, float py)
{
	CurRot = angle;
	sf::Transform temp;
	return temp.rotate(angle, px, py);
}

sf::Transform _Transform::SetSca(float px, float py)
{
	CurSca = sf::Vector2f(px, py);
	sf::Transform temp;
	return temp.scale(px, py);
}

sf::Transform _Transform::SetSca(float Radius)
{
	CurSca = sf::Vector2f(Radius, Radius);
	sf::Transform temp;
	return temp.scale(Radius, Radius);
}

sf::Transform _Transform::MoveObj2D(float PX, float PY)//focus on this later, when needed
{
	sf::Transform temp;
	
	return temp;
}

sf::Vector2f _Transform::GetPos()
{
	return CurPos;
}

float _Transform::GetRot()
{
	return CurRot;
}

sf::Vector2f _Transform::GetSca()
{
	return CurSca;
}
