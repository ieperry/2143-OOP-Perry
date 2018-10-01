/*
* Course: CMPS 2143
* Assignment: P01
* Purpose: Creates a vector array with overload
* operations and tests all of the class's functions.
*
* Isha Perry
* 09/14/18
* github: ieperry
*/
#include <iostream>
#include <string> 
#include "MyVector.h" 

using namespace std;

int main() 
{
  //Creates an instance of MyVector
	MyVector V(10); 
  MyVector W(10); 

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

  int a[] = {1,2,3,4,5,6,7};  

  W.pushBack(5); 

  //Pushes array onto W vector
  W.pushBack(a, 7); 

  //Prints the values in W
  cout << endl << "W: ";
  W.print();  
  
  //Checks [] operator
  cout << endl << W[0] << endl;  

  //Checks * operator
  W = V * W;  

  //Checks << operator
  cout << endl << "W: " << W << endl;;

  //Checks + operator
  V = V + W;
  cout << endl << "V: " << V << endl; 

  //Checks - operator
  W = V - W; 
  cout << endl << "W: " << W << endl;

  //Checks == operator
  if (W == V)
  {
    cout << "They equal!" << endl;
  }
  else
  {
    //Ensures that W does not hold zeroes
    for (int i = 0; i < W.vIndex() + 1; i++)
    {
      W[i] = i + 2;
    }
  }

  //Tests / operator
  V = V / W; 
  cout << endl << "V: " << V << endl;

  MyVector V2 = V; 

  //Checks V and V2 to see if they are equal
  if (V == V2)
  {
    cout << endl << "V2: " << V2 << endl; 
    cout << "The '=' operator works!" <<  endl; 
  }

	return 0; 
}
