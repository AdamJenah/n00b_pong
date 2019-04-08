#pragma once
#include "NoobClass.h"
#include "_Transform.h"

class Sprite2D;
class Rectangle2D;
class BaseComponent
{
public:
	BaseComponent(Sprite2D *_gameObject, bool moveAble, bool renderAble);
	BaseComponent(Rectangle2D *_gameObject, bool moveAble, bool renderAble);
	~BaseComponent();

	void draw(sf::RenderWindow &window, sf::Drawable &shape);
	void Start(_Transform &transform);
	void Update(float msec, _Transform &transform, sf::RenderWindow &window);

	Sprite2D *SpritegameObject;
	Rectangle2D *RectgameObject;
	_Transform *transform;
	bool Renderable;
	bool Moveable;
};