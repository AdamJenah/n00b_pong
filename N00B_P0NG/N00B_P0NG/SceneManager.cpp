#include "SceneManager.h"


SceneManager::SceneManager()
{
}


SceneManager::~SceneManager()
{
}

void SceneManager::Scene()
{
	//ALL OBJECTS ARE CREATED HERE
	test.Rectangle2D(10, 20, 30, 30, 0, sf::Color::Cyan);
	test.AddObject(&test);
	test.Circle2D(10, 60, 60, 0, sf::Color::Magenta);
	test.AddObject(&test);
}

