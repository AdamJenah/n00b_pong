#include "Objects.h"

Objects::Objects()
{
}

Objects::~Objects()
{
}

void Objects::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
	//std::cout << "Drawing" << std::endl;
	target.draw(*this, sf::RenderStates::Default);
	
}

void Objects::Update(sf::RenderWindow& _window)//WE NEED TO UPDATE EACH OBJECT IN THAT ARRAY
{
	//update the transform as well
	draw(_window, sf::RenderStates::Default);
}