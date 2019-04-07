#include "BaseComponent.h"
#include "Sprite2D.h"
#include "Rectangle2D.h"

BaseComponent::BaseComponent(Sprite2D *_gameObject, bool moveAble, bool renderAble)
{
	SpritegameObject = _gameObject;
}

BaseComponent::BaseComponent(Rectangle2D *_gameObject, bool moveAble, bool renderAble)
{
	RectgameObject = _gameObject;
}

BaseComponent::~BaseComponent()
{
}

void BaseComponent::draw(sf::RenderWindow &window, sf::Drawable *shape)
{
	if (Renderable)
	{
		window.draw(*shape);
	}
}

void BaseComponent::Start(_Transform *transform)//make templates for Rectgameobject
{
	if (Moveable)
	{
		/*RectgameObject->transform.SetPos(transform->GetPos().x, transform->GetPos().y);
		RectgameObject->transform.SetRot(transform->GetRot(), transform->GetPos().x, RectgameObject->transform.GetPos().y);
		RectgameObject->transform.SetSca(transform->GetSca().x, transform->GetSca().y);*/
	}
}

void BaseComponent::Update(float msec, _Transform *transform, sf::RenderWindow &window)
{
	if (Renderable)
	{
		draw(window, &SpritegameObject->ThisSpriteHold);//only drawing the sprite, twice for rectangle2D
	}
	if (Moveable)
	{
		//RectgameObject->transform.SetPos(transform->GetPos().x, transform->GetPos().y);
		//RectgameObject->transform.SetRot(transform->GetRot(), transform->GetPos().x, RectgameObject->transform.GetPos().y);
		//RectgameObject->transform.SetSca(transform->GetSca().x, transform->GetSca().y);
	}
}