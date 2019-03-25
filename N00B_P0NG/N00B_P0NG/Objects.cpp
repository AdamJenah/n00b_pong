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
		component->Start();
	}
}

void Objects::Update(float msec, sf::RenderWindow &window)
{
	//if (parent) { //This node has a parent...
	//	worldTransform = parent->worldTransform * transform;
	//}
	//else { //Root node, world transform is local transform!
	//	worldTransform = transform;
	//}
	for (BaseComponent* component : components)
	{
		component->Update(msec, window);
	}
}