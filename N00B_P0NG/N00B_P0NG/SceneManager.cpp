#include "SceneManager.h"

SceneManager::SceneManager()
{
}


SceneManager::~SceneManager()
{
}

void SceneManager::LoadTextures()
{
	if (!_texture.loadFromFile("TEST_TEXTURE.jpg", sf::IntRect(10, 10, 32, 32)))
	{
		std::cout << "Failed To Load Texture" << std::endl;
	}
	else
	{
		_texture.loadFromFile("TEST_TEXTURE.jpg");
	}
}

// Do Draw objects here but the updates are called in Objects
void SceneManager::Scene()
{
	//ALL OBJECTS ARE CREATED HERE
	test_0.MySprite2D(30, 30, 60, 60, 0, _texture, sf::Color::Cyan);
	AddObject(&test_0);
}

void SceneManager::UpdateObj(sf::RenderWindow& _window, sf::Time elapsedTime)
{
	for (int i = 0; i < ObjNum; i++)
	{
		sceneObjects[i]->Update(_window, elapsedTime, sceneObjects.at[i]);
	}
}

void SceneManager::AddObject(Objects *pushObj)
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


