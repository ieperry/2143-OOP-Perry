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

  void MyVector::pushBack(int *arr, int arrSize) 
  {
    index++; 

   //Checks if list is full
  	if (index == vSize - 1) 
    {
     //Increases the size
      vSize = vSize * 1.5;
    }

   //Uses index to place item
	  for(int i = 0; index <= arrSize; i++)
    {
     vPointer[index] = arr[i];
     index++;  
    }

    index--; 
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

int MyVector::vIndex() 
{
  return index;  
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

/*
* An overload operator that allows the vector
* to act like an array
*
* Param: an integer, the index in the vector
* Return: an integer within the vector
*/
int& MyVector::operator[](int i) 
{ 
  if (i >= vSize)  
  { 
    cout << "Error: Index out of bounds\n"; 
    exit(0);    
  }
    else if(i > index)
  {
    cout << "Warning: Vector at " << i << " is undefined\n";
  }
  return vPointer[i];  
}

/*
* An overload operator that allows a vector
* to be assigned to another vector
*
* Param: an initialized vector in main
* Return: a vector that holds the same values
*/
/*MyVector MyVector::operator=(const MyVector& V)
{
  MyVector vTemp;
  
  //Loops through vector
  for (int i = 0; i < index + 1; i++)
  {
    //Places values of vector to the temp
    vTemp.pushBack(V[i]);  
  }

  return vTemp; 
}*/

/*
* An overload operator that allows one vector
* to be added to the values of another
*
* Param: a vector, the one being added
* Return: a vector with the values of both vectors
*/
MyVector MyVector::operator+(MyVector& V2)
{  
  MyVector vTemp; 

  //Tests to see which vector is bigger
  if(index >= V2.vIndex())  
  {
    for (int i = 0; i < index + 1; i++)
    {
      //Sets first vector equal to the temp
      vTemp[i] = vPointer[i]; 
    }
    for (int i = 0; i < V2.vIndex() + 1; i++)
    {
      //Adds values and stores them in temp
      vTemp[i] = vPointer[i] + V2[i]; 
    } 
      
  } 
  else if (index < V2.vIndex())
  {
    for (int i = 0; i < V2.vIndex() + 1; i++)  
    {
      //Sets second vector equal to temp
      vTemp.pushBack(V2[i]); 
    } 
    for (int i = 0; i < index + 1; i++) 
    {
      vTemp[i] = vPointer[i] + V2[i]; 
    }
  }

  return vTemp;  
}

/*
* An overload operator that allows one vector
* to be subtracted to the values of another
*
* Param: a vector, the one being subtracted
* Return: a vector with the values of both vectors
*/
MyVector MyVector::operator-(MyVector& V2)
{
  MyVector vTemp;   
   
   if(index >= V2.vIndex())   
  {
    for (int i = 0; i < index + 1; i++)
    {
      //Sets first vector equal to the temp
      vTemp.pushBack(vPointer[i]);
    }
    for (int i = 0; i < V2.vIndex() + 1; i++)
    {
      //Subtracts the values and stores in temp
      vTemp[i] = vPointer[i] - V2[i]; 
    } 
  } 
  else if (index < V2.vIndex())
  {
    for (int i = 0; i < V2.vIndex() + 1; i++)  
    {
      //Sets second vector equal to the temp
      vTemp.pushBack(V2[i]); 
    }
    for (int i = 0; i < index + 1; i++)  
    {
      vTemp[i] = vPointer[i] - V2[i]; 
    }
  }

  return vTemp; 
}

/*
* An overload operator that allows one vector
* to be multiplied by the values of another
*
* Param: a vector, the one being multiplied
* Return: a vector with the values of both vectors
*/
MyVector MyVector::operator*(MyVector& V2)
{
  MyVector vTemp;   
   
   if(index >= V2.vIndex())   
  {
    //Sets first vector equal to the temp
    for (int i = 0; i < index + 1; i++)
    {
      vTemp.pushBack(vPointer[i]);
    }
    for (int i = 0; i < V2.vIndex() + 1; i++)
    {
      //Multiplies the values and stores in temp
      vTemp[i] = vPointer[i] * V2[i]; 
    } 
  } 
  else if (index < V2.vIndex())
  {
    for (int i = 0; i < V2.vIndex() + 1; i++)  
    {
      //Sets second vector equal to the temp
      vTemp.pushBack(V2[i]); 
    }
    for (int i = 0; i < index + 1; i++)  
    {
      vTemp[i] = vPointer[i] * V2[i]; 
    }
  }

  return vTemp; 
}

/*
* An overload operator that allows one vector
* to be divided by the values of another
*
* Param: a vector, the one being divided
* Return: a vector with the values of both vectors
*/
MyVector MyVector::operator/(MyVector& V2) 
{
  MyVector vTemp;   
   
   if(index >= V2.vIndex())   
  {
    for (int i = 0; i < index + 1; i++)
    {
      //Sets first vector equal to the temp
      vTemp.pushBack(vPointer[i]);
    }
    for (int i = 0; i < V2.vIndex() + 1; i++)
    {
      //Sends error whenever divided by zero
      if(V2[i] == 0)
      {
        cout << "Error: Divied by Zero\n";
        exit(0);
      }
      //Divides values and stores into temp
      vTemp[i] = vPointer[i] / V2[i]; 
    } 
  } 
  else if (index < V2.vIndex())
  {
    for (int i = 0; i < V2.vIndex() + 1; i++)  
    {
      //Sets second vector equal to the temp
      vTemp.pushBack(V2[i]); 
    }
    for (int i = 0; i < index + 1; i++)  
    {
      if(V2[i] == 0)
      {
        cout << "Error: Divied by Zero\n";
        exit(0); 
      }
      vTemp[i] = vPointer[i] / V2[i]; 
    }
  }

  return vTemp; 
}

/*
* An overload operator that allows vector to
* be compared to one another
*
* Param: another vector that is being compared
* Return: a bool, sees if the vectors are equal
*/
bool MyVector::operator==(MyVector& V2)
{
  //If the sizes of the vectors are different,
  //then the equality is false
  if (index > V2.vIndex() | index < V2.vIndex()) 
  {
    return false;
  }

  //Loops and checks the values in the vectors
  for(int i = 0; i < index; i++)  
  {
    if (vPointer[i] != V2[i]) 
    {
      return false;
    }
  }

  //If nothing returned is false, then the 
  //vectors are equal
  return true;
}

/*
* An overload operator that allows a vector
* to be printed out without calling a method
*
* Param: ostream, prints the vector and
*        the vector that will be printed
* Return: ostream, prints the values inside vector
*/
ostream& operator<<(ostream& os, const MyVector& V)  
{
  //Loops and prints the values in vector
  for(int i = 0; i < V.index + 1; i++)
	{
    os << V.vPointer[i] << " ";   
  }  

  return os; 
} 
