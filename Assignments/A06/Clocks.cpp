/*
* Course: CMPS 2143
* Assignment: A06
* Purpose: Create a class "counter" to increment or decrement time. Counter
* should inherit from the Group class and be able to print out the timer
* to the sfml window. The user can change the clock's postion, color, 
* background color, and it's movement.
*
* Isha Perry
* 11/16/18
* github: ieperry
*/

#include <SFML/Graphics.hpp>
#include <iostream>
#include "Group.h" 

// https://www.sfml-dev.org/tutorials/2.5/system-time.php

using namespace std;

//My clock that inherits from group
class Counter: public Group
{

private:
	sf::Time start; //Holds the start of the timer
	sf::Time end; //Holds the end of the timer
	sf::Time elapsed; //Holds the time that has passed

	sf::Text text; //The number that will be printed out
	sf::Font font; //Holds the font for the number
	sf::Color textColor; //Holds the color for the text
	sf::RectangleShape rectangle; //The background for text
	
	int fontSize; //Holds the size of text
	float dx; //The speed the clock will move
	float dy;
	bool finished; //Holds whether or not the clock has finished 

public:

	/*
	* Default constuctor for counter
	*
	* Param: Clock allows get elapsed time to be used
	* Return: None
	*/
	Counter()
	{
		//Checks if font is loaded and throws error if not
		if (!font.loadFromFile("Segment7Standard.otf"))
		{
			cout << "Error: Cannot load 'Segment7Standard'";
			exit(0);
		}

		//Sets the speed for clock
		dx = 1; 
		dy = 1;

		//Sets the rectangle and text to default values
		setRecText(); 

	}

	/*
	* Overloaded constuctor for counter
	*
	* Param: fSize is an int for the size of text; 
	*		 fColor is a char (r, b, g, or t) that determines the color of text;
	*		 backColor is a char (r, b, g, or t) that determines the color 
	*			of background;
	*		 bordColor is a char (r, b, g, or t) that determines the color of 
	*			the outline color of the background;
	*		 posX and posY are integers that determine the position of clock
	* Return: None
	*/
	Counter(int fSize, char fColor, char backColor, char bordColor,int posX, int posY)
	{
		if (!font.loadFromFile("Segment7Standard.otf"))
		{
			cout << "Error: Cannot load 'Segment7Standard'";
			exit(0);
		}

		dx = 1;
 		dy = 1;

		//Sets rectangle and text to the users input
		setRecText(fSize, fColor, backColor, bordColor, posX, posY);

	}

	/*
	* Prints the clock to the sfml window
	*
	* Param: Clock to start the timer;
	*		 time1 and time2 are integers to increment or decrement clock
	* Return: None
	*/
	void printClock(sf::Clock clock, int time1, int time2)
	{
		finished = false;
		setTimer(time1, time2);

		if (time1 < time2) //Incrementing
		{
			incClock(clock, time2);
		}
		else if (time1 == time2) //Finished
		{
			text.setString("0"); 
		}
		else //Decrementing 
		{
			decClock(clock, time1);
		}
	}

	/*
	* Sets rectangle and text for an infinite clock
	*
	* Param: None
	* Return: None
	*/
	void setRecText()
	{
		//Default size and color of text
		fontSize = 48;
		textColor = sf::Color(0, 255, 0);

		//Sets rectangle to default colors, origin, and position
		rectangle.setSize(sf::Vector2f(100, 100));
		rectangle.setFillColor(sf::Color::Transparent);
		rectangle.setOutlineColor(sf::Color::Transparent);
		rectangle.setOutlineThickness(2);
		rectangle.setOrigin(50, 50);
		rectangle.setPosition(100, 100);

		//Sets text to default size and color
		text.setFont(font);
		text.setString("0");
		text.setCharacterSize(fontSize);
		text.setFillColor(textColor);
		text.setStyle(sf::Text::Bold);

		//Push rectangle and text into vector
		this->push_back(rectangle);
		this->push_back(text);

	}

	/*
	* Sets rectangle and text according to the input of the user
	*
	* Param: fSize is an integer to set the font size of text;
	*		 fColor is a char (r, b, g, or t) that sets the color of text;
	*		 backColor is a char (r, b, g, or t) that sets the color 
	*			of background;
	*		 bordColor is a char (r, b, g, or t) that sets the color of 
	*			the outline color of the background;
	*		 posX and posY are integers that set the position of clock
	* Return: None
	*/
	void setRecText(int fSize, char fColor, char backColor, char bordColor, int posX, int posY)
	{

		fontSize = fSize; 

		//Sets the font color to red, green, blue, or transparent
		//but defaults to green
		switch (fColor)
		{
			case 'r': textColor = sf::Color(255, 0, 0);
				break;
			case 'g': textColor = sf::Color(0, 255, 0);
				break;
			case 'b': textColor = sf::Color(0, 0, 255);
				break;
			case 't': textColor = sf::Color(0,0,0,255); 
				break;
			default: textColor = sf::Color(0, 255, 0);
		}

		//Sets the background color to red, green, blue, or transparent
		//but defaults to blck
		switch (backColor)
		{
			case 'r': rectangle.setFillColor(sf::Color::Red); 
				break;
			case 'g': rectangle.setFillColor(sf::Color::Green);
				break;
			case 'b': rectangle.setFillColor(sf::Color::Blue); 
				break;
			case 't': rectangle.setFillColor(sf::Color::Transparent);
				break;
			default: rectangle.setFillColor(sf::Color::Black);
		}

		//Sets the border color for background to red, green, blue, 
		//or transparent but defaults to green
		switch (bordColor)
		{
			case 'r': rectangle.setOutlineColor(sf::Color::Red);
				break;
			case 'g': rectangle.setOutlineColor(sf::Color::Green);
				break;
			case 'b': rectangle.setOutlineColor(sf::Color::Blue);
				break;
			case 't': rectangle.setFillColor(sf::Color::Transparent);
				break;
			default: rectangle.setOutlineColor(sf::Color::Green);
		}

		//Sets rectangle to the position passed in by user
		rectangle.setSize(sf::Vector2f(100, 100));
		rectangle.setOutlineThickness(2);
		rectangle.setOrigin(50, 50);
		rectangle.setPosition(posX, posY); 

		//Sets text to the position passed in by user
		text.setFont(font);
		text.setString("0");
		text.setCharacterSize(fontSize);
		text.setFillColor(textColor);
		text.setStyle(sf::Text::Bold);
		text.setPosition(posX, posY);

		this->push_back(rectangle);
		this->push_back(text); 
	}

	/*
	* Increments clock
	*
	* Param: Clock to get elapsed time;
	*		 time2 is the integer that is when the clock stops
	* Return: None
	*/
	void incClock(sf::Clock clock, int time2)
	{
		//Gets elapsed time and makes it an integer
		elapsed = clock.getElapsedTime();
		int e = elapsed.asSeconds();

		//Sets elapsed time to text
		string time = to_string(e);
		text.setString(time);

		//Sets origin of text
		sf::Vector2f origin(10, 10);
		text.setOrigin(origin);

		//Sets finished to true if elapsed time is the time passed in
		if (e == time2 && time2 != 0)
		{
			finished = true;
		}
	}

	/*
	* Increments clock
	*
	* Param: Clock to get elapsed time;
	*		 time1 is the integer that is when the clock stops
	* Return: None
	*/
	void decClock(sf::Clock clock, int time1)
	{
		//Sets elapsed time and start time
		elapsed = clock.getElapsedTime();
		int e = elapsed.asSeconds();
		int st = start.asSeconds();

		//The clock will stop decrementing at 0
		if ((st - e) <= 0)
		{
			text.setString("0"); 
		}
		else
		{
			string time = to_string(st - e);
			text.setString(time);
		}

		sf::Vector2f origin(10, 10);
		text.setOrigin(origin);

		if (e == time1)
		{
			finished = true;
		}
	}

	/*
	* Moves the clock so that the clocks bounce around the window
	*
	* Param: integers of window width and height to stop the clock
	*		 bouncing out of the window
	* Return: None
	*/
	void moveClock(int winWidth, int winHeight)
	{ 
		//Gets the position of the text
		sf::Vector2f pos = text.getPosition();

		//Stops the clock from bouncing past window
		//and moves the clock in the opposite direction
		if (pos.x > winWidth - 50 || pos.x < 50)
		{
			dx = dx *= -1;
		}
		if (pos.y > winHeight - 50 || pos.y < 50)
		{
			dy = dy *= -1; 
		}
		 
		//Moves text and rectangle together
		text.move(dx, dy); 
		rectangle.move(dx, dy); 
	}
	
	/*
	* Sets the start and end of timer
	*
	* Param: integers of start and end of timer
	* Return: None
	*/
	void setTimer(int beg, int fin)
	{
		start = sf::seconds(beg);
		end = sf::seconds(fin);
	}

	/*
	* Restarts timer
	*
	* Param: Clock so that the timer resets
	* Return: None
	*/
	void resetTimer(sf::Clock clock)
	{
		clock.restart(); 
	}

	/*
	* Determines whether or not the clock has reached the end
	*
	* Param: None
	* Return: bool to determine if it is the end of clock
	*/
	bool isFinished()
	{
		return finished; 
	}

};

int main()
{
	sf::RenderWindow window(sf::VideoMode(300, 400), "SFML CLOCK");

	sf::Clock clock; 

	//Initializes three clocks
	Counter myClock2(48, 'd', 'b', 'r', 50, 50); 
	Counter myClock1(48, 'd', 'r', 'b', 250, 250);
	Counter myClock3(48, 'd', 't', 't', 100, 100);
	
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		
		window.clear();

		//Starts timer and increments or decrements clock
		myClock2.printClock(clock, 0, 60); 
		myClock1.printClock(clock, 10, 0);
		myClock3.printClock(clock, 0, 0); 

		//Prints clocks to sfml window
		window.draw(myClock2);
		window.draw(myClock1); 
		window.draw(myClock3);

		//Bounces the clocks around in the window
		myClock2.moveClock(300, 400);
		myClock1.moveClock(300, 400); 
		myClock3.moveClock(300, 400);
		
		window.display();

		//Closes window whenever the incrementing clock is finished
		if (myClock2.isFinished() == true) 
		{
			window.close();
		}
	}

	return 0;
}
