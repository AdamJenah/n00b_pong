#pragma once
#include "NoobClass.h"
#include "Objects.h"
#include "_Transform.h"


class BaseComponent
{
	friend class Objects;
public:
	BaseComponent(Objects* _gameObject, bool moveAble, bool renderAble);
	~BaseComponent();

	void draw(sf::RenderWindow &window);
	void Start();
	void Update(float msec, sf::RenderWindow &window);

	Objects* gameObject;
	_Transform transform;
	sf::Sprite sprite;
	bool Renderable;
	bool Moveable;
};

