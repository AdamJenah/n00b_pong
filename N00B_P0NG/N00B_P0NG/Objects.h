#pragma once
#include "NoobClass.h"
#include "Rectangle2D.h"
#include "Circle2D.h"
#include "Text2D.h"
#include "Sprite2D.h"
#include "Physics.h"

class Objects : public sf::Drawable
{
public:
	Objects();
	~Objects();

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	// Creates Textures/Images funtion: DrawImage()
	// Creates Rectangle function: DrawRect()
	// Creates Circle function: DrawRect()
	// Creates Text Function: DrawText()
	// Creates Draw functions for other objects as necessary

	void Update(sf::RenderWindow& _window);

	Physics PhysicsEngine;

	Rectangle2D MyRect;
	Circle2D MyCircle;
	Text2D MyText;
	Sprite2D MySprite;
};

