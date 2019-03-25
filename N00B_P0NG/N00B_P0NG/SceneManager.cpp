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
	//test(test_1, false, true);
	//test.sprite.setTexture(_texture);
	//test_1.AddComponent(&test);
	//test.transform.SetPos(100, 100);
	//AddObject(&test_1);
}

void SceneManager::UpdateObj(sf::Time elapsedTime, sf::RenderWindow& _window)
{
	for (int i = 0; i < ObjNum; i++)
	{
		sceneObjects[i]->Update(elapsedTime.asSeconds(), _window);
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


