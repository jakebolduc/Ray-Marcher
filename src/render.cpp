#include <SFML/Graphics.hpp>
#include <iostream>
#include "vector.h"
#include "raymarching.h"

#define WIDTH 256
#define HEIGHT 256

void Vprint(vector::vector A){
	printf("(%f, %f, %f)", A.x, A.y, A.z);
}

int main()
{
	sf::RenderWindow window(sf::VideoMode(WIDTH,HEIGHT),"RayMarching");
//do stuff here
	raymarch::RaymarchScene scene;








	while (window.isOpen())
	{
		sf::Event event;
		while(window.pollEvent(event))
		{
			if(event.type == sf::Event::Closed)
			{
				window.close();
				std::cout<<"window closed\n";
			}
		}

	}
}
