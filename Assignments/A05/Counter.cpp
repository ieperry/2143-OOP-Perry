/*
* Course: CMPS 2143
* Assignment: A05
* Purpose: Create a class "counter" to increment or decrement time.
*
* Isha Perry
* 11/2/18
* github: ieperry
*/

#include <SFML/Graphics.hpp>
#include <iostream>

// https://www.sfml-dev.org/tutorials/2.5/system-time.php

using namespace std;

class Counter 
{

private:
	sf::Time start;
	sf::Time end;
	sf::Time elapsed;
	bool finished; 

public:

	/*
	* Default constuctor for counter
	*
	* Param: Clock allows get elapsed time to be used
	* Return: None
	*/
	Counter(sf::Clock clock)
	{
		setTimer(time1, time2); //Sets start and end values
		finished = false; //The timer will never be finished
		
		//Places the time to elapsed and print it to the screen
		elapsed = clock.getElapsedTime(); 
		cout << elapsed.asSeconds(); 
	}

	/*
	* Overloaded constuctor for counter
	*
	* Param: Clock allows get elapsed time to be used
	* Return: None
	*/
	Counter(sf::Clock clock, int time1, int time2)
	{
		
		finished = false; //Sets finished value
		setTimer(time1, time2); //Sets start and end values

		if (time1 <= time2) //increment
		{
			elapsed = clock.getElapsedTime();
			
			//Converts elapsed to int
			int e = elapsed.asSeconds();
			
			//Prints seconds to screen
			cout << e << endl;  
			
			//Checks if timer is ending value
			if (e == time2) 
			{
				finished = true;
			}
		}
		else //decrement
		{
			elapsed = clock.getElapsedTime();

			//Converts elapsed and start to int
			int e = elapsed.asSeconds();
			int st = start.asSeconds(); 

			//Prints in decreasing order
			cout << st - e << endl; 
			
			//Checks if timer is beginning value
			if (e == time1)
			{
				finished = true;
			}
		}
	}
	
	/*
	* Sets starting and ending values
	*
	* Param: integer for the beginning; integer for the end
	* Return: None
	*/
	void setTimer(int beg, int fin)
	{
		start = sf::seconds(beg);
		end = sf::seconds(fin);
	}
	
	/*
	* Resets the clock 
	*
	* Param: Clock calls a function to reset
	* Return: None
	*/
	void resetTimer(sf::Clock clock)
	{
		clock.restart(); 
	}
	
	/*
	* Returns the variable finished
	*
	* Param: None
	* Return: a bool that determines if timer is finished
	*/
	bool isFinished()
	{
		return finished; 
	}

};

int main()
{
	//Creates SFML window
	sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");

	//Starts Clock
	sf::Clock clock; 
	
	//Runs SFML window
	while (window.isOpen())
	{
		sf::Event event;
		
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		Counter myClock1(clock, 5, 0); // start at 5 and decrement to 0
		Counter myClock2(clock, 0, 5); // start at 0 and increment to 5

		window.clear();
		//window.draw(shape);
		window.display();
		
		//Checks if counter is finished 
		if (myClock1.isFinished() == true) 
		{
			window.close();
		}
	}

	return 0;
}
