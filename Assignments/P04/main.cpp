/*
* Course: CMPS 2143
* Assignment: P04
* Purpose: Create your own game of life class and game board to play
* John Conway's Game of Life. The cells that will be on the board must
* hold a value to explain if it is alive or dead and the amount of 
* neighbors. The game board will hold an array of these cells. 
* The functions in the game board will apply the rules of the game,
* print the board out, and play out the game using SFML.
*
* Isha Perry
* 10/19/18
* github: ieperry
*/

#include <iostream>
#include <fstream>
#include <string> 
#include <SFML/Graphics.hpp> 

using namespace std;

//My game of life cell
struct golCell
{
	bool isAlive; //keep an alive or dead value
	int neighborCount; //counts the alives cell beside an individual cell

	//The shape and size for the automation
	sf::RectangleShape rect; 
	int width;
	int height;

	/*
	* Default constuctor for golCell
	*
	* Param: None
	* Return: None
	*/
	golCell()
	{
		isAlive = 0;
		neighborCount = 0;
		width = 10;
		height = 10; 

		//sets color from SFML library
		rect.setSize(sf::Vector2f(width, height)); 
		rect.setFillColor(sf::Color::Cyan); 
		rect.setOutlineColor(sf::Color::Yellow);  
		rect.setOutlineThickness(1);
	}

	/*
	* Determines the place of the cell on the worls
	* function from sfml_game_of_life_2.cpp
	*
	* Param: an integer for x; an interger for y
	* Return: None
	*/
	void setCellPos(int x, int y) 
	{
		rect.setPosition(x*width, y*height);
	}
};

//Has the world and the rules for the cells
class GameOfLife
{
private:

	//Helps lower frame rate
	int frameRate;
	int frameCount;

	//Keeps the rows and cols of the game board
	int rows;
	int cols;

	//Keeps the width and height of the world
	int width;
	int height; 

	//2D array of cells
	golCell** gameBoard;
	 

public:

	//SFML window to print the world and game board
	sf::RenderWindow window;

	//Grid for the cells
	golCell **world;

	/*
	* Parameterized constuctor for GameOfLife
	* Also creates the window for SFML
	*
	* Param: an integer that the user can assign
	* Return: None
	*/
	GameOfLife(int w, int h)
	{
		//My computer has a slow frame rate
		//so the variable is set to a small number
		frameCount = 0;
		frameRate = 5;
		
		//Will recieve the values of rows and cols from initGameBoard
		rows = 0;
		cols = 0;

		//The size of the window taken from the main
		width = w;
		height = h; 

		//Creates window
		window.create(sf::VideoMode(width, height), "Game of Life");

		//Sets the world 
		world = new golCell*[width];   

		for (int i = 0; i < width; i++)
		{
			world[i] = new golCell[height];

			for (int j = 0; j < width; j++)
			{
				//Places the cells on the world
				world[i][j].setCellPos(i, j); 
			}
		}

	}

	/*
	* Reads the infile and places values into cell
	*
	* Param: a string passed by reference from the main
	* Return: None
	*/
	void initGameBoard(string &input) 
	{
		//opens infile
		ifstream infile; 
		infile.open(input); 

		string line;
		string name;

		//Reads name and ignores
		infile >> name;

		//Reads and places values into rows and cols
		infile >> rows >> cols; 

		//Sets a 2D array with values from infile
		gameBoard = new golCell*[rows];

		for (int i = 0; i < rows; i++)
		{
			gameBoard[i] = new golCell[cols];
		}

		//Places alive and death values into game board
		for (int i = 0; i < rows; i++)
		{
			infile >> line;

			for (int j = 0; j < cols; j++)
			{
				gameBoard[i][j].isAlive = line[j] - 48;
				gameBoard[i][j].neighborCount = 0;
			}
		}
		
		//Closes infile
		infile.close();
	}

	/*
	* Opens SFML window and set colors for cells
	*
	* Param: None
	* Return: None
	*/
	void displayWorld()
	{
		window.clear();

		//Flips height and width for SFML
		for (int i = 0; i < height; i++)
		{
			for (int j = 0; j < width; j++) 
			{
				//Displays the rectangles for world
				window.draw(world[i][j].rect);
			}
		}

		//Flips cols and rows for SFML
		for (int i = 0; i < cols; i++)
		{
			for (int j = 0; j < rows; j++)
			{
				//Displays alive cells
				if (gameBoard[j][i].isAlive == true)
				{
					world[i][j].rect.setFillColor(sf::Color::Red);
					world[i][j].rect.setOutlineColor(sf::Color::Black);
				}
				else
				{
					world[i][j].rect.setFillColor(sf::Color::Cyan);
					world[i][j].rect.setOutlineColor(sf::Color::Black);
				}
			}
		}

		window.display();
	}

	/*
	* Determines if cell is on game board
	*
	* Param: an integer for the row; an integer for the col
	* Return: a true or false value
	*/
	bool onGameBoard(int r, int c)
	{
		return (r >= 0 && r < rows && c >= 0 && c < cols);
	}

	/*
	* Counts the alive cells around a cell
	*
	* Param: an integer for the row; an integer for the col
	* Return: an integer for the number of alive cells
	*/
	int countNeighbors(int r, int c)
	{
		int count = 0;

		//Counts whenever a nearby cell is alive
		if (onGameBoard(r - 1, c - 1) == true && gameBoard[r - 1][c - 1].isAlive == true)
		{
			count++;
		}
		if (onGameBoard(r, c - 1) == true && gameBoard[r][c - 1].isAlive == true)
		{
			count++;
		}
		if (onGameBoard(r - 1, c) == true && gameBoard[r - 1][c].isAlive == true)
		{
			count++;
		}
		if (onGameBoard(r + 1, c + 1) == true && gameBoard[r + 1][c + 1].isAlive == true)
		{
			count++;
		}
		if (onGameBoard(r + 1, c) == true && gameBoard[r + 1][c].isAlive == true)
		{
			count++;
		}
		if (onGameBoard(r, c + 1) == true && gameBoard[r][c + 1].isAlive == true)
		{
			count++;
		}
		if (onGameBoard(r - 1, c + 1) == true && gameBoard[r - 1][c + 1].isAlive == true)
		{
			count++;
		}
		if (onGameBoard(r + 1, c - 1) == true && gameBoard[r + 1][c - 1].isAlive == true)
		{
			count++;
		}

		return count;
	}

	/*
	* Puts number of alive cells into all the cells
	*
	* Param: None
	* Return: None
	*/
	void neighborCells()
	{
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				gameBoard[i][j].neighborCount = countNeighbors(i, j);
			}
		}
	}

	/*
	* Applies rules for Game of Life to cell
	*
	* Param: an integer for rows; an integer for cols
	* Return: None
	*/
	void Rules(int r, int c)
	{
		//Rules for the alive cell
		if (gameBoard[r][c].isAlive == true)
		{	//Kills cell if there less than 2 alive cells or more than 3 alive cells
			if (gameBoard[r][c].neighborCount < 2 || gameBoard[r][c].neighborCount > 3)
			{
				gameBoard[r][c].isAlive = false;
			}
			//Keep cell alive if there are 2 or 3 alive cells
			else if (gameBoard[r][c].neighborCount == 2 || gameBoard[r][c].neighborCount == 3)
			{
				gameBoard[r][c].isAlive = true;
			}
		}
		else //Rules for the dead cell
		{	//Resurrects a dead cell if there are 3 alive cells
			if (gameBoard[r][c].neighborCount == 3)
			{
				gameBoard[r][c].isAlive = true;
			}
		}

	}

	/*
	* Determines the frame rate
	*
	* Param: None
	* Return: an integer, either 1 or 0
	*/
	int theFrameRate() 
	{
		frameCount++;

		//Uses mod to slow framerate
		if (frameCount % frameRate == 0)
		{
			return 0; 
		}

		return 1; 
	}

	/*
	* Makes new generation of cells
	*
	* Param: an integer that the user can assign
	* Return: None
	*/
	void nextGen()
	{
		//Counts the alive cells 
		neighborCells();

		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				//Apply rules and resets the number of alive cells
				Rules(i, j);
				gameBoard[i][j].neighborCount = 0;
			}
		}

	}

	/*
	* Prints a header to outfile
	*
	* Param: ostream passed by reference
	* Return: None
	*/
	void outfileHeader(ofstream &outfile)
	{
		outfile << "Isha Perry" << endl;
		outfile << "P04 - Game of Life" << endl;
		outfile << "10/18/18" << endl << endl;

	}

	/*
	* Prints game board to the outfile
	*
	* Param: a string passed by reference from the main
	* Return: None
	*/
	void printGameBoard(string &output)
	{
		//Opens outfile
		ofstream outfile;
		outfile.open(output);

		outfileHeader(outfile); 

		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				//Prints the 1 for the alive cells
				outfile << gameBoard[i][j].isAlive;
			}
			outfile << endl;
		}

		//Closes outfile
		outfile.close();
	}

	/*
	* Runs the world and game board with SFML
	*
	* Param: an integer for the amount of runs
	* Return: None
	*/
	void run(int gens)
	{
		int runTimes = 0;

		//Runs simulation
		while (window.isOpen())
		{
			sf::Event event;

			frameCount++;

			//Displays world to screen
			//My computer was too slow for the animation
			//displayWorld();

			while (window.pollEvent(event))
			{

				if (event.type == sf::Event::Closed)
				{
					window.close();
				}

			}

			//Updates game board
			nextGen();
			runTimes++;

			//Closes window when the simulation at a certain point
			if (runTimes == gens)
			{
				break;
			}

			//Slows the frame rate by postponing the display
			//if (frameCount % frameRate == 0)
			//{
			//
			//displayWorld();
			//}
		}
	}

};

/*
* Calls functions to play the Game of Life
*
* Param: command line operators to read the infile and outfile
* Return: an integer to stop the program
*/
int main(int argc, char** argv)
{
	//Places the command lines into strings
	string input = argv[1];
	string output = argv[3];
	string gens = argv[2];

	//Creats a game of life with 600 as the width and height
	GameOfLife G(600, 600);

	//Reads from infile and places values into game board
	G.initGameBoard(input);    
	
	//Runs game for X times
	G.run(338);  

	//Prints the alive and dead cells to output
	G.printGameBoard(output); 

	return 0;
}
