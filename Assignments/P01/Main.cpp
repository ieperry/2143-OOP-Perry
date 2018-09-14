/*
* Course: CMPS 2143
* Assignment: P01
* Purpose: Creates a basic vector array and
* tests all of the class's functions.
*
* Isha Perry
* 09/14/18
*/
#include <iostream>
#include <string> 
#include "MyVector.h" 

using namespace std;

int main() 
{
  //Creates an instance of MyVector
	MyVector V(10); 
	int x = 1;
	
  //Attempts to removes from empty vector
	V.popBack(10);

  //Pushes specific values to vector
	V.pushBack(13);
	V.pushBack(31); 
	V.pushBack(73); 

  //Prints the vector 
	V.print();

  //Pushes 10000 even values to vector
	for (int i = 0; i < 10000; i++)
	{
		x = i * 2;
		V.pushBack(x);
	}

  //Prints size
	x = V.size();
	cout << x << " " << endl;

  //Removes 998 values from vector
	for (int i = 0; i < 9998; i++)
	{
		x = V.popBack(10); 
	}

  //Prints size once more
	x = V.size();
	cout << x << " " << endl;

  //Prints the vector array
  V.print();

	return 0; 
}
