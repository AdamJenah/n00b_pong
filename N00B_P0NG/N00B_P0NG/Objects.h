#pragma once
#include "NoobClass.h"
#include "BaseComponent.h" 
#include "_Transform.h"

class BaseComponent;
class Objects
{
public:
	Objects();
	~Objects();

	void AddComponent(BaseComponent* component);
	_Transform* transform;
	void Start();
	void Update(float msec, sf::RenderWindow &window);

private:
	std::list<BaseComponent*> components;
};

