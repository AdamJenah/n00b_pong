#include "SceneManager.h"

SceneManager::SceneManager()
{
}


SceneManager::~SceneManager()
{
}

// Do Draw objects here but the updates are called in Objects
void SceneManager::Scene()
{
	//ALL OBJECTS ARE CREATED HERE
	test_0.MyRect.MyRect2D(10, 20, 30, 30, 0, sf::Color::Cyan);
	AddObject(&test_0);
	test_1.MyCircle.MyCircle2D(10, 60, 60, 0, sf::Color::Magenta);
	AddObject(&test_1);
}

void SceneManager::UpdateObj(sf::RenderWindow& _window)
{
	for (int i = 0; i < ObjNum; i++)
	{
		sceneObjects[i]->Update(_window);
	}
}

void SceneManager::AddObject(Objects * pushObj)
{
	sceneObjects.push_back(pushObj);
	ObjNum++;
	std::cout << "Object added" << std::endl;
	std::cout << "Number of Objects: " + std::to_string(ObjNum) << std::endl;
}

void SceneManager::RemoveObject(Objects * Index)
{
	//must swap object to delete, to the top, then pop the object.
	sceneObjects.pop_back();
}


