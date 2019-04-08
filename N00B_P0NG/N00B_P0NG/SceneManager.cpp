#include "SceneManager.h"

SceneManager::SceneManager()
{
	testSprite = 0;
	testRect = 0;
}


SceneManager::~SceneManager()
{
}

void SceneManager::LoadTextures()
{
	if (!_texture.loadFromFile("Assets/Wood.jpg"))
	{
		std::cout << "Failed To Load Texture" << std::endl;
	}
	else
	{
		std::cout << "Loaded Texture" << std::endl;
	}
}

// Do Draw objects here but the updates are called in Objects
void SceneManager::Scene()
{
	testSprite->MySprite2D(1, 1, 10, 10, 0, _texture);
	test_1.AddComponent(testSprite);
	//testRect.MyRect2D(100, 100, 10, 10, 0, sf::Color::Cyan);
	//test_1.AddComponent(&testRect);

	AddObject(&test_1);
}

void SceneManager::Start()
{
	testSprite = new Sprite2D;
	testRect = new Rectangle2D;
	test_1 = *new Objects;
	LoadTextures();
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
	//must swap object to delete; swap to the top, then pop the object.
	sceneObjects.pop_back();
}


