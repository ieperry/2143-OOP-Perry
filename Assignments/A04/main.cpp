/*
* Course: CMPS 2143
* Assignment: A04
* Purpose: Slow the frame rate with given code
*
* Isha Perry and Terry Griffin
* 10/5/18
* github: ieperry
*/

#include <SFML/Graphics.hpp>

using namespace sf;

//This is a given function from SFML that can slow rate:
//void sf::Window::setFramerateLimit(unsigned int limit)	

struct golCell {
	bool isAlive;
	int neighborCount;
	sf::RectangleShape Rect; 
	int Width;
	int Height;

	golCell() {
		Width = 10;
		Height = 10;
		Rect.setSize(sf::Vector2f(Width, Height));
		Rect.setFillColor(Color::Green);
		Rect.setOutlineColor(Color::Black);
		Rect.setOutlineThickness(1);
	}

	void setCellPos(int x, int y) {
		Rect.setPosition(x*Width, y*Height);
	}

};

struct gameOfLife {
	int Width;
	int Height;
	
	//Added code:
	int frameCount; 
	int frameRate;
	
RenderWindow Window;
golCell** World;

gameOfLife(int width, int height) {
	Width = width;
	Height = height;
	frameCount = 0;
	frameRate = 5; //Slow the frameRate by increasing number

	Window.create(VideoMode(Width, Height), "Game of Life");

	World = new golCell*[height];

	for (int i = 0; i<height; i++) {
		World[i] = new golCell[width];
		for (int j = 0; j<width; j++) {
			World[i][j].setCellPos(i, j);
		}
	}
}

void drawWorld() {
	Window.clear();
	for (int i = 0; i<Height; i++) {
		for (int j = 0; j<Width; j++) {
			Window.draw(World[i][j].Rect);
		}
	}
	Window.display();
}
};

int main() {

	gameOfLife Gol(500, 500);

	while (Gol.Window.isOpen())
	{
		Event event;
		while (Gol.Window.pollEvent(event))
		{
			Gol.frameCount++;

			//Displays window every X time
			if (Gol.frameCount % Gol.frameRate == 0) 
				Gol.drawWorld();

			if (event.type == Event::Closed)
				Gol.Window.close();
		}
	}

	return 0;
}
