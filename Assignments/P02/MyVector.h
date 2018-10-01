/*
*Initializes the class for MyVector, and
*lists all of it's methods
*
*Isha Perry
*/

#include <iostream>

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
int vSize;
int index; 
public:

  //Default constructor for class
  MyVector();

  //Parameterized contructor for class
  MyVector(int arrSize);

  //Adds item to back of vector array
  void pushBack(int item);

  //Adds the items from any array to the back
  //of the vector array
  void pushBack(int *arr, int arrSize); 

  //Removes item from the back of vector array
  int popBack(int arrSize);

  //Prints the vector
	void print();

  //Returns the size of the vector array
  int size();

  //Returns the index of the vector array 
  int vIndex();  

  //Finds how full the vector array is with 
  //a percentage
  double percentFull();

  //Allows the vector to act like an array
  int& operator[](int i); 

  //Sets the values of two vector arrays to 
  //equal each other
  void operator=(const MyVector& V); 

  //Allows two vectors to be added together
  MyVector operator+(MyVector& V2);   

  //Allows two vectors to be subtracted together
  MyVector operator-(MyVector& V2);

  //Allows two vectors to be multiplied together
  MyVector operator*(MyVector& V2);

  //Allows two vectors to be divided together
  MyVector operator/(MyVector& V2); 

  //Tests the equality of two vectors
  bool operator==(MyVector& V2); 

  //Prints the vector using "cout" 
  friend ostream& operator<<(ostream& os, const MyVector& V);
};

