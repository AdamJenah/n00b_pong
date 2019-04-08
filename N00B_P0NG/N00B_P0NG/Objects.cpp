#include "Objects.h"

Objects::Objects()
{
	transform = new _Transform(0, 0);
	AddComponent((BaseComponent*)transform);
}

Objects::~Objects()
{
}

void Objects::AddComponent(BaseComponent * component)
{
	components.push_back(component);
}

void Objects::Start()
{
	for (BaseComponent* component : components)
	{
		component->Start(*transform);
	}
}

void Objects::Update(float msec, sf::RenderWindow &window)
{

	//also update yourself

	for (BaseComponent* component : components)
	{
		component->Update(msec, *transform, window);
	}
}