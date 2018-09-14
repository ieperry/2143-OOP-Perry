/*
* Defines all of the methods for MyVector.
*
* Isha Perry
*/
#include <iostream> 
#include <string> 
#include "MyVector.h" 

using namespace std;

/*
* Default constuctor for Node
*
* Param: None
* Return: None
*/
MyVector::MyVector()
{
	vSize = 10;
	vPointer = new int[vSize]; 
	index = -1; 
}

/*
* Parameterized constuctor for MyVector
*
* Param: an integer that the user can assign
* Return: None
*/
MyVector::MyVector(int arrSize)
{
	vSize = arrSize;
	vPointer = new int[vSize]; 
	index = -1; 
}

/*
* Adds an integer to the back of the vector
* and grows whenever an item is added to the 
* full list.
*
* Param: any integer 
* Return: None
*/
void MyVector::pushBack(int item) 
{	
	index++; 

  //Checks if list is full
	if (index == vSize - 1) 
	{
    //Uses index to place item
	  vPointer[index] = item; 

    //Increases the size
    vSize = vSize * 1.5;
  }

	 vPointer[index] = item; 
  } 

/*
* Takes item from back of list and 
* returns the integer.
*
* Param: an integer; the vector size
* Return: an integer; item from the list
*/
int MyVector::popBack(int arrSize)
{
	int item = 0; 
	int test = vSize / 2; 

  //Checks to see if list is empty
	if (index == -1)
	{
		cout << "Error: the list is empty\n";
		return item; 
	}

  //Checks how full the vector list is and
  //uses test to see if it is safe to reduce
  //the list
	if (percentFull() >= 0.40 && test >= vSize) 
	{
    //Takes integer from list
		item = vPointer[index];

    //Reduces size
		vSize = vSize / 2;
	}
	else
	{
		item = vPointer[index]; 

    //Sets size to orginal size of list
		vSize = arrSize;  
	}

	index--; 

	return item; 
}

/*
* Prints the vector list to the screen
*
* Param: None
* Return: None
*/
void MyVector::print()
{ 
  //Uses loop to print the list
	for (int i = 0; i < index + 1; i++)  
	{
		cout << vPointer[i] << " ";
	}
	cout << endl;
}

/*
* Returns size 
*
* Param: None
* Return: the size, an integer
*/
int MyVector::size()
{
	return vSize; 
}

/*
* Finds how full the vector is with a
* percentage and return it as a decimal
*
* Param: None
* Return: a double, the percentage
*/
double MyVector::percentFull()
{
	double val;

	val = index / vSize; 

	return val; 
}
