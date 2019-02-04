//empty, due to moving all code to main.cpp file because, thats the file the sfml looks for first in a file named main.cpp
#include "NoobClass.h"
#include "NoobInit.h"
#include "SceneManager.h"

int main()
{
	N00BP0NG n00bp0ng;
	n00bp0ng.HasFreeDiskSpace();
	n00bp0ng.ReadCPUSpeed();
	n00bp0ng.CheckMemory();

	sf::RenderWindow window(sf::VideoMode(1000, 800), "SFML works!");
	//sf::CircleShape shape(100.f);
	//shape.setFillColor(sf::Color::Green);

	SceneManager SceneM;

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		for (int i = 0; i <= SceneM.test.ObjNum; i++)
		{
			SceneM.test.Update(window);//draws objects by passing in window
		}
		window.display();
	}

	return 0;
}