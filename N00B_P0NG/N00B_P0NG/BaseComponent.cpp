#include "BaseComponent.h"
#include "Sprite2D.h"
#include "Rectangle2D.h"
#include "Paddle.h"

BaseComponent::BaseComponent(Sprite2D *_gameObject, bool moveAble, bool renderAble)
{
	SpritegameObject = _gameObject;
	Moveable = moveAble;
	Renderable = renderAble;
}

BaseComponent::BaseComponent(Rectangle2D *_gameObject, bool moveAble, bool renderAble)
{
	RectgameObject = _gameObject;
	Moveable = moveAble;
	Renderable = renderAble;
}

BaseComponent::~BaseComponent()
{
}

void BaseComponent::draw(sf::RenderWindow &window, sf::Drawable &shape)
{
	if (Renderable)
	{
		//std::cout << "Display" << std::endl;
		window.draw(shape);
	}
}

void BaseComponent::Start(_Transform &transform)//make templates for all components
{
	if (Moveable)
	{
		/*SpritegameObject->transform.SetPos(transform->GetPos().x, transform->GetPos().y);
		SpritegameObject->transform.SetRot(transform->GetRot(), transform->GetPos().x, SpritegameObject->transform.GetPos().y);
		SpritegameObject->transform.SetSca(transform->GetSca().x, transform->GetSca().y);*/
	}
}

void BaseComponent::Update(float msec, _Transform &transform, sf::RenderWindow &window)
{
	if (Renderable)
	{
		draw(window, SpritegameObject->ThisSpriteHold);
	}
	if (Moveable)
	{
		//SpritegameObject->transform.SetPos(transform->GetPos().x, transform->GetPos().y);
		//SpritegameObject->transform.SetRot(transform->GetRot(), transform->GetPos().x, SpritegameObject->transform.GetPos().y);
		//SpritegameObject->transform.SetSca(transform->GetSca().x, transform->GetSca().y);
	}
}