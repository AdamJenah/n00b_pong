#include "BaseComponent.h"

BaseComponent::BaseComponent(Objects* _gameObject, bool moveAble, bool renderAble)
{
	gameObject = _gameObject;
}


BaseComponent::~BaseComponent()
{
}

void BaseComponent::draw(sf::RenderWindow &window)
{
	window.draw(sprite);
}

void BaseComponent::Start()
{
}

void BaseComponent::Update(float msec, sf::RenderWindow &window)
{
	if (Renderable)
	{
		draw(window);
	}
	if (Moveable)
	{
		transform.SetPos(gameObject->transform->GetPos().x, gameObject->transform->GetPos().y);
		transform.SetRot(gameObject->transform->GetRot(), gameObject->transform->GetPos().x, gameObject->transform->GetPos().y);
		transform.SetSca(gameObject->transform->GetSca().x, gameObject->transform->GetSca().y);
	}
}
