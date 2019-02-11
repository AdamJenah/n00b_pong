#include "Circle2D.h"

Circle2D::Circle2D()
{
}

Circle2D::~Circle2D()
{
}

sf::CircleShape Circle2D::MyCircle2D(float Radius, float PX, float PY, float Angle, sf::Color _color)
{
	sf::CircleShape temp;
	temp.setRadius(Radius);
	temp.setOrigin(Radius / 2, Radius / 2);
	temp.setFillColor(_color);
	ObjTransform.SetPos(PX, PY);
	ObjTransform.SetRot(Angle, PX, PY);
	ObjTransform.SetSca(Radius);
	temp.setPosition(ObjTransform.GetPos());
	temp.setRotation(ObjTransform.GetRot());
	temp.setScale(ObjTransform.GetSca());
	//temp.setTexture(); //used to set the texture, use when needed
	return temp;
}
