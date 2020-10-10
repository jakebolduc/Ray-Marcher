#include <SFML/Graphics.hpp>
#include <iostream>
#include "vector.h"
#include "raymarching.h"

#define WIDTH 512
#define HEIGHT 512
#define ZOOM 512

void Vprint(vector::vector A){
	printf("(%f, %f, %f)\n", A.x, A.y, A.z);
}


int main()
{
	sf::RenderWindow window(sf::VideoMode(WIDTH,HEIGHT),"RayMarching");

	raymarch::RaymarchScene scene;
	#include "scene000.h"

//do stuff here

	//pixArray -> texture -> sprite -> draw
	sf::Uint8* pixels = new sf::Uint8[WIDTH * HEIGHT * 4];
	sf::Texture texture;
	texture.create(WIDTH, HEIGHT);
	sf::Sprite sprite;
	sprite.setTexture(texture);

//render
	for (size_t y = 0; y < HEIGHT; y++) {
		for (size_t x = 0; x < WIDTH; x++) {
			int imgpos = (y*WIDTH + x) *4;
			vector::vector pos = scene.raymarch(vector::set(0,0,0), vector::normalize(vector::set(x-(HEIGHT/2),y-(WIDTH/2),ZOOM)));
			VECT_FLOAT dist = std::min(vector::dist(vector::set(0,0,0),pos),255.0);
			pixels[imgpos+0] = dist;
			pixels[imgpos+1] = dist;
			pixels[imgpos+2] = dist;
			pixels[imgpos+3] = 255;

			if( y == 255 | y==256){
				printf("%f - ", dist);
				Vprint(pos);
			}

		}
	}

	texture.update(pixels);
	window.draw(sprite);


	window.display();

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
		window.draw(sprite);
		window.display();
	}
}
