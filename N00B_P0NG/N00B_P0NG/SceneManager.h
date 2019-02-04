#pragma once
#include "NoobClass.h"
#include "Objects.h"

class SceneManager
{
public:
	SceneManager();
	~SceneManager();

	Objects test_0;
	Objects test_1;

	std::vector <Objects*> sceneObjects;
	int ObjNum = 0;

	void Scene();
	void UpdateObj(sf::RenderWindow& _window);
	void AddObject(Objects *pushObj);
	void RemoveObject(Objects *Index);
};

