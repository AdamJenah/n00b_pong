#include "BaseComponent.h"

BaseComponent::BaseComponent()
{
}

BaseComponent::~BaseComponent()
{
}

void BaseComponent::drawShape(sf::RenderTarget &target, sf::Sprite _sprite) const
{
	target.draw(_sprite, sf::RenderStates::Default);
}
