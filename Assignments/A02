/**
* Course: CMPS 2413
* Assignment: A02
* Purpose: Creates, assigns, and prints out two dynamic lists that like an array. 
* Then, it combines the two lists together, and prints the combined lists.
*
* Terry Griffin and Isha Perry
* 09/05/18
*/

#include <iostream>

using namespace std;

int A[100];

//Creates the nodes for the list
struct Node
{
    int x;
    Node *next;
    
    /**
    * Default constuctor for Node
    *
    * Param: None
    * Return: None
    */
    Node()
    {
        x = -1;
        next = NULL;
    }
    
    /**
    * Parameterized constuctor for Node
    *
    * Param: an integer that the user can assign
    * Return: None
    */
    Node(int n)
    {
        x = n;
        next = NULL;
    }
};


//Class that creates List and holds it's methods
class List
{
  private:
    Node *Head;
    Node *Tail;
    int Size;

  public:
    /**
    * Default  constuctor for Node
    *
    * Param: None
    * Return: None
    */

    List()
    {
        Head = Tail = NULL;
        Size = 0;
    }

    /**
    * Places value into List; inserts at the end of List
    *
    * Param: value, int, that will be held in the Node
    * Return: None
    */
    void Push(int val)
    {
        // allocate new memory and init node
        Node *Temp = new Node(val);

        if (!Head && !Tail)
        {
            Head = Tail = Temp;
        }
        else
        {
            Tail->next = Temp;
            Tail = Temp;
        }
        Size++;
    }
    
    /**
    * Places value into List; inserts at the beginning of List
    *
    * Param: value, int, that will be held in the Node
    * Return: None
    */
    void Insert(int val)
    {
        // allocate new memory and init node
        Node *Temp = new Node(val);

        // figure out where it goes in the list

        Temp->next = Head;
        Head = Temp;
        if (!Tail)
        {
            Tail = Head;
        }
        Size++;
    }
    
    /**
    * Prints values from list
    *
    * Param: None
    * Return: None
    */
    void PrintTail()
    {
        cout << Tail->x << endl;
    }
    
    /**
    * Prints an arrow to seperate the numbers in the list
    *
    * Param: None
    * Return: a string that prints "->" between values
    */
    string Print()
    {
        Node *Temp = Head;
        string list;

        while (Temp != NULL)
        {
            list += to_string(Temp->x) + "->";
            Temp = Temp->next;
        }

        return list;
    }

    // not implemented 
    int Pop()
    {
        Size--;
        return 0; //
    }
    
    /**
    * Implements "+" operator to combine Lists
    *
    * Param: the second List is passed by reference 
    * Return: returns a combined List
    */
    List operator+(const List &Rhs)
    {
        // Create a new list that will contain both when done
        List NewList;

        // Get a reference to beginning of local list
        Node *Temp = Head;

        // Loop through local list and Push values onto new list
        while (Temp != NULL)
        {
            NewList.Push(Temp->x);
            Temp = Temp->next;
        }

        // Get a reference to head of Rhs
        Temp = Rhs.Head;

        // Same as above, loop and push
        while (Temp != NULL)
        {
            NewList.Push(Temp->x);
            Temp = Temp->next;
        }

        // Return new concatenated version of lists
        return NewList;
    }

    /**
    * Implements "[]" so that the list acts like and array
    *
    * Param: an integer that is the location in the List
    * Return: returns an integer value from the node
    */
    int operator[](int index)
    {
        Node *Temp = Head;

        if (index >= Size)
        {
            cout << "Index out of bounds, exiting";
            exit(0);
        }
        else
        {

            for (int i = 0; i < index; i++)
            {
                Temp = Temp->next;
            }
            return Temp->x;
        }
    }
    
    /**
    * Implements "<<" to outstream List
    *
    * Param: ostream is passed by reference; List is printed
    * Return: returns ostream and prints the Nodes within the List
    */
    friend ostream &operator<<(ostream &os, List L)
    {
        os << L.Print();
        return os;
    }
};

int main(int argc, char **argv)
{
    List L1;
    List L2;
    
    //Pushes values into List 1
    for (int i = 0; i < 25; i++)
    {
        L1.Push(i);
    }
    
    //Pushes different values into List 2
    for (int i = 50; i < 100; i++)
    {
        L2.Push(i);
    }

    //cout << L1 << endl;
    L1.PrintTail();
    L2.PrintTail();
    
    //Combines List 1 and List 2; the combined Lists are held in List 3
    List L3 = L1 + L2;
    cout << L3 << endl;
    
    //Tests the operator[] function
    cout << L3[5] << endl;
    return 0;
}
