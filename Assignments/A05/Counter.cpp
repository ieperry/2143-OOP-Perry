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
		start = sf::seconds(50);
		end = sf::seconds(50); 
		finished = false;

		elapsed = clock.getElapsedTime();
		cout << elapsed.asSeconds();
	}

	/*
	* Overloaded constuctor for counter
	*
	* Param: Clock elapsed time for the variable elapsed
	* Return: None
	*/
	Counter(sf::Clock clock, int time1, int time2)
	{
		
		finished = false; 
		setTimer(time1, time2);

		if (time1 <= time2) 
		{
			//increment
			elapsed = clock.getElapsedTime();

			int e = elapsed.asSeconds();

			cout << e << endl;  
			
			if (e == time2)
			{
				finished = true;
			}
		}
		else
		{
			//decrement
			elapsed = clock.getElapsedTime();

			int e = elapsed.asSeconds();
			int st = start.asSeconds(); 

			cout << st - e << endl; 

			if (e == time1)
			{
				finished = true;
			}
		}
	}
	
	void setTimer(int beg, int fin)
	{
		start = sf::seconds(beg);
		end = sf::seconds(fin);
	}

	void resetTimer(sf::Clock clock)
	{
		clock.restart(); 
	}

	bool isFinished()
	{
		return finished; 
	}

};

int main()
{
	sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");

	sf::Clock clock; 
	
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		//Counter myClock1(clock, 5, 0); // start at 5 and decrement to 0
		Counter myClock2(clock, 0, 5); // start at 0 and increment to 5

		window.clear();
		//window.draw(shape);
		window.display();

		if (myClock2.isFinished() == true) 
		{
			window.close();
		}
	}

	return 0;
}
