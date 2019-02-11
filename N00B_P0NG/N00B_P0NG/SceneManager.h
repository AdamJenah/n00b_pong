#pragma once
#include "NoobClass.h"
#include "Objects.h"
#include "Sprite2D.h"

class SceneManager
{
public:
	SceneManager();
	~SceneManager();

	Sprite2D test_0;
	Objects test_1;

	std::vector <Objects*> sceneObjects;
	int ObjNum = 0;
	sf::Texture _texture;

	void LoadTextures();
	void Scene();
	void UpdateObj(sf::RenderWindow& _window, sf::Time elapsedTime);
	void AddObject(Objects *pushObj);
	void RemoveObject(Objects *Index);
};

