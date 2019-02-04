#pragma once
#include "NoobClass.h"
#include "_Transform.h"

class Objects
{
public:
	Objects();
	~Objects();
	// Creates Textures/Images funtion: DrawImage()
	// Creates Rectangle function: DrawRect()
	// Creates Circle function: DrawRect()
	// Creates Text Function: DrawText()
	// Creates Draw functions for other objects as necessary

	_Transform ObjTransform;

	void Update(sf::RenderWindow& _window);
	void DrawObj(sf::RenderWindow& _window, int i);

	int ObjNum = 0;
	std::vector <Objects*> ObjArray;//need to create an array of objects
	
	void AddObject(Objects *pushObj);
	void RemoveObject(Objects *Index);

	sf::RectangleShape Rectangle2D(float TL, float BR, float PX, float PY, float Angle, sf::Color _color);
	sf::CircleShape Circle2D(float Radius, float PX, float PY, float Angle, sf::Color _color);
	sf::Text Text2D(sf::String message, float size, float PX, float PY, float Angle, sf::String _style, sf::Color _color);
	sf::Sprite Sprite2D(float TL, float BR, float PX, float PY, float Angle, sf::Texture _texture, sf::Color _color);
};

