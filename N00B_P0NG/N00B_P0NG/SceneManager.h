#pragma once
#include "NoobClass.h"
#include "Objects.h"
#include "Sprite2D.h"

class SceneManager
{
public:
	SceneManager();
	~SceneManager();

	Objects test_1;
	//BaseComponent test;
	std::vector <Objects*> sceneObjects;
	int ObjNum = 0;
	sf::Texture _texture;

	void LoadTextures();
	void Scene();
	void UpdateObj(sf::Time elapsedTime, sf::RenderWindow& _window);
	void AddObject(Objects *pushObj);
	void RemoveObject(Objects *Index);
};

