#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include <math.h>
#include "nlohmann/json.hpp" // from https://github.com/nlohmann/json
#include "vector.h"
#include "raymarching.h"

using json = nlohmann::json;

#define PI 3.14159265

// aspect ratios other that 1:1 do not work properly


void Vprint(vector::vector A){
	printf("(%f, %f, %f)\n", A.x, A.y, A.z);
}


int main(){

	int size[2] = {512,512};
	int zoom = 256;
	raymarch::RaymarchScene scene;

	#include "scene.h"

	sf::RenderWindow window(sf::VideoMode(size[0],size[1]),"RayMarching");
	window.setVerticalSyncEnabled(true);
	printf("FOV: %f\n", (2*atan2(size[0]/2, zoom)*180/PI));

	//pixArray -> texture -> sprite -> draw
	sf::Uint8* pixels = new sf::Uint8[size[0] * size[1] * 4];
	sf::Texture texture;
	texture.create(size[0], size[1]);
	sf::Sprite sprite;
	sprite.setTexture(texture);

//render
	for (int y = 0; y < size[1]; y++) {
		for (int x = 0; x < size[0]; x++) {
			int imgpos = (y*size[0] + x) *4;
			vector::vector pos = scene.raymarch(vector::set(0,0,0), vector::normalize(vector::set(x-(size[1]/2),y-(size[0]/2),zoom)));
			//int glow = scene.raymarchGlow(vector::set(0,0,0), vector::normalize(vector::set(x-(size[1]/2),y-(size[0]/2),zoom)));
			//VECT_FLOAT dist = std::min(vector::dist(vector::set(0,0,0),pos),255.0);
			pixels[imgpos+0] = scene.glow * 0.2;
			pixels[imgpos+1] = scene.glow * 0.8;
			pixels[imgpos+2] = scene.glow * 1.0;
			pixels[imgpos+3] = 255;

		}
	}

	texture.update(pixels);
	window.draw(sprite);


	window.display();


	/*
	//output to file
	sf::Image image;
	image.create(size[0],size[1],pixels);
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
	return 0;
}
