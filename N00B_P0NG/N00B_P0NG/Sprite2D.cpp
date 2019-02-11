#include "Sprite2D.h"

Sprite2D::Sprite2D()
{
}


Sprite2D::~Sprite2D()
{
}

sf::Sprite Sprite2D::MySprite2D(float TL, float BR, float PX, float PY, float Angle, sf::Texture _texture, sf::Color _color)
{
	sf::Sprite temp;
	temp.setColor(_color);
	temp.setOrigin(ObjTransform.GetSca().x / 2, ObjTransform.GetSca().y / 2);
	ObjTransform.SetPos(PX, PY);
	ObjTransform.SetRot(Angle, PX, PY);
	ObjTransform.SetSca(TL, BR);
	temp.setPosition(ObjTransform.GetPos());
	temp.setRotation(ObjTransform.GetRot());
	temp.setScale(ObjTransform.GetSca());
	_texture.setSmooth(true);
	temp.setTexture(_texture);
	return temp;
}