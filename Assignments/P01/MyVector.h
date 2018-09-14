/*
*Initializes the class for MyVector, and
*lists all of it's methods
*
*Isha Perry
*/

#include <iostream>

using namespace std;

class MyVector
{
private:
	int *vPointer;
	int vSize = 10;
	int index; 
public:

  //Default constructor for class
  MyVector();

  //Parameterized contructor for class
	MyVector(int arrSize);

  //Adds item to back of vector array
	void pushBack(int item);

  //Removes item from the back of vector array
	int popBack(int arrSize);

  //Prints the vector
	void print();

  //Returns the size of the vector array
	int size();

  //Finds how full the vector array is with 
  //a percentage
	double percentFull();

};

