#include "Rectangle2D.h"

Rectangle2D::Rectangle2D()
{
}

Rectangle2D::~Rectangle2D()
{
}

sf::RectangleShape Rectangle2D::MyRect2D(float TL, float BR, float PX, float PY, float Angle, sf::Color _color)
{
	sf::RectangleShape temp;
	temp.setSize(sf::Vector2f(TL, BR));
	temp.setOrigin(ObjTransform.GetSca().x / 2, ObjTransform.GetSca().y / 2);
	temp.setFillColor(_color);
	ObjTransform.SetPos(PX, PY);
	ObjTransform.SetRot(Angle, PX, PY);
	ObjTransform.SetSca(TL, BR);
	temp.setPosition(ObjTransform.GetPos());
	temp.setRotation(ObjTransform.GetRot());
	temp.setScale(ObjTransform.GetSca());
	//temp.setTexture(); //used to set the texture, use when needed
	return temp;
}
