#include "Sprite2D.h"

Sprite2D::Sprite2D() : BaseComponent(this, true, true)
{
}

Sprite2D::~Sprite2D()
{
}

void Sprite2D::MySprite2D(float TL, float BR, float PX, float PY, float Angle, sf::Texture _texture, sf::Color _color)
{
	sf::Sprite temp;
	temp.setColor(_color);
	transform.SetPos(PX, PY);
	transform.SetRot(Angle, PX, PY);
	transform.SetSca(TL, BR);
	temp.setOrigin(transform.GetSca().x / 2, transform.GetSca().y / 2);
	temp.setPosition(transform.GetPos());
	temp.setRotation(transform.GetRot());
	temp.setScale(transform.GetSca());
	temp.setTexture(_texture, false);
	ThisSpriteHold = temp;
}

void Sprite2D::MySprite2D(float TL, float BR, float PX, float PY, float Angle, sf::Texture *_texture)
{
	sf::Sprite temp;
	temp.setOrigin(transform.GetSca().x / 2, transform.GetSca().y / 2);
	transform.SetPos(PX, PY);
	transform.SetRot(Angle, PX, PY);
	transform.SetSca(TL, BR);
	temp.setPosition(transform.GetPos());
	temp.setRotation(transform.GetRot());
	temp.setScale(transform.GetSca());
	temp.setTexture(*_texture, false);
	ThisSpriteHold = temp;
}