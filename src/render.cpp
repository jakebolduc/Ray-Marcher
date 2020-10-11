#include <SFML/Graphics.hpp>
#include <iostream>
#include <math.h>
#include "vector.h"
#include "raymarching.h"

#define PI 3.14159265

#define WIDTH 2000
#define HEIGHT 2000
#define ZOOM 1000

void Vprint(vector::vector A){
	printf("(%f, %f, %f)\n", A.x, A.y, A.z);
}


int main()
{
	sf::RenderWindow window(sf::VideoMode(WIDTH,HEIGHT),"RayMarching");
	printf("FOV: %f\n", (2*atan2(WIDTH/2, ZOOM)*180/PI));

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
	for (int y = 0; y < HEIGHT; y++) {
		for (int x = 0; x < WIDTH; x++) {
			int imgpos = (y*WIDTH + x) *4;
			vector::vector pos = scene.raymarch(vector::set(0,0,0), vector::normalize(vector::set(x-(HEIGHT/2),y-(WIDTH/2),ZOOM)));
			//int glow = scene.raymarchGlow(vector::set(0,0,0), vector::normalize(vector::set(x-(HEIGHT/2),y-(WIDTH/2),ZOOM)));
			VECT_FLOAT dist = std::min(vector::dist(vector::set(0,0,0),pos),255.0);
			pixels[imgpos+0] = scene.glow * 0.5;
			pixels[imgpos+1] = scene.glow * 1.0;
			pixels[imgpos+2] = scene.glow * 0.5;
			pixels[imgpos+3] = 255;

		}
	}

	texture.update(pixels);
	window.draw(sprite);


	window.display();


	/*
	//output to file
	sf::Image image;
	image.create(WIDTH,HEIGHT,pixels);
	if(!image.saveToFile("frame000.png")){
		printf("failed to save image\n");
	}//*/

	//*
	//output to window
	while (window.isOpen()){
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
	}//*/
}
