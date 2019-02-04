#include "Text2D.h"



Text2D::Text2D()
{
}


Text2D::~Text2D()
{
}

sf::Text Text2D::MyText2D(sf::String message, float size, float PX, float PY, float Angle, sf::String _style, sf::Color _color)
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
