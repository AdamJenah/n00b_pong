#include "Objects.h"

Objects::Objects()
{
}

Objects::~Objects()
{
}

// Do Draw objects here but the updates are called in SceneManager


void Objects::AddObject(Objects *pushObj)//use this to add to array
{
	ObjArray.push_back(pushObj);
	ObjNum++;
}

void Objects::RemoveObject(Objects *Index)//use this to remove from array
{
	//must swap object to delete, to the top, then pop the object.
}

void Objects::Update()//WE NEED TO UPDATE EACH OBJECT IN THAT ARRAY AND ALSO ADD A REPEATING UPDATE
{
	for (int i = 0; i <= ObjNum; i++)
	{
		ObjArray[i]->Draw();
	}
}

Objects Objects::Draw()//fix
{
	return *this;
}

sf::RectangleShape Objects::Rectangle2D(float TL, float BR, float PX, float PY, float Angle, sf::Color _color)//figure out difference between size/radius and scale
{
	sf::RectangleShape temp;
	temp.setSize(sf::Vector2f(TL, BR));
	temp.setOrigin(TL / 2, BR / 2);
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

sf::CircleShape Objects::Circle2D(float Radius, float PX, float PY, float Angle, sf::Color _color)
{
	sf::CircleShape temp;
	temp.setRadius(Radius);
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

sf::Text Objects::Text2D(sf::String message, float size, float PX, float PY, float Angle, sf::String _style, sf::Color _color)
{
	sf::Text temp;
	temp.setString(message);
	temp.setCharacterSize(size);
	temp.setFillColor(_color);
	/*switch(_style.getData)//fix setting the style
	{
		case _style.getData = "Bold":
			temp.setStyle(sf::Text::Bold);
			break;
		case _style.getData = "Italic":
			temp.setStyle(sf::Text::Italic);
			break;
		case _style.getData = "Underlined":
			temp.setStyle(sf::Text::Underlined);
			break;
		case _style.getData = "StrikeThrough":
			temp.setStyle(sf::Text::StrikeThrough);
			break;
		case _style.getData = "Regular":
			temp.setStyle(sf::Text::Regular);
			break;
		default: //meaning no style
			break;
	}*/
	ObjTransform.SetPos(PX, PY);
	ObjTransform.SetRot(Angle, PX, PY);
	ObjTransform.SetSca(size);
	temp.setPosition(ObjTransform.GetPos());
	temp.setRotation(ObjTransform.GetRot());
	temp.setScale(ObjTransform.GetSca());
	//temp.setTexture(); //used to set the texture, use when needed
	return temp;
}

sf::Sprite Objects::Sprite2D(float TL, float BR, float PX, float PY, float Angle, sf::Texture _texture, sf::Color _color)
{
	sf::Sprite temp;
	temp.setColor(_color);
	ObjTransform.SetPos(PX, PY);
	ObjTransform.SetRot(Angle, PX, PY);
	ObjTransform.SetSca(TL, BR);
	temp.setPosition(ObjTransform.GetPos());
	temp.setRotation(ObjTransform.GetRot());
	temp.setScale(ObjTransform.GetSca());
	temp.setTexture(_texture);
	return temp;
}