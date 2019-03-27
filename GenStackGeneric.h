#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

template <class T>

class GenStackGeneric
{
    public:
        GenStackGeneric(); //constructor
        GenStackGeneric(int maxSize);
        ~GenStackGeneric(); //destructor

        void push(T d);
        T& pop();
        T& peek(); //aka top

        int getSize(); //returns the size of the stack
        bool isEmpty(); //boolean condition: returns true if the stack is empty; returns false if otherwise
        bool isFull(); //boolean condition: returns true if the stack is full

        int size; //the size of the stack
        int top; //the index of the top element of the stack. Also used to determine if stack is empty or full

        T *myArray; //pointer to an object of type T
};


template <class T>
GenStackGeneric<T>::GenStackGeneric() //default constructor
{
	myArray = NULL;
	size = 0;
	top = 0;
}

template <class T>
GenStackGeneric<T>::GenStackGeneric(int maxSize) //overloaded constructor
{
    myArray = new T[maxSize];
    size = maxSize;
    top = -1;
}

template <class T>
GenStackGeneric<T>::~GenStackGeneric() //destructor
{
	//we need to reallocate the memory used by our GenStack object (the array)
	delete [] myArray;
}

template <class T>
void GenStackGeneric<T>::push(T d)
{
	if(top == size - 1)
	{
		T* a = new T[size+1];
		size +=1;
		myArray = a;
	}
    //make sure stack is not full
    //you are responsible for error/bound checking

    myArray[++top] = d;
}

template <class T>
T& GenStackGeneric<T>::pop()
{
    //error checking. Make sure the array is not empty

	if(size == 0)
	{
		cout << "Error. Stack is empty!" << endl;
        exit(1);
	}

	return myArray[top--];
}

template <class T>
T& GenStackGeneric<T>::peek()
{
    //error checking: make sure the array is not empty
	if(size == 0)
	{
		cout <<"Error: The stack is empty. Cannot remove an element";
        exit(1);
	}
    return myArray[top]; //return the top element in the stack. This method does not remove the top element
}

template <class T>
bool GenStackGeneric<T>::isFull() //checks to see if the stack is full
{
    return (top == size - 1);
}

template <class T>
bool GenStackGeneric<T>::isEmpty() //checks to see if the stack is empty
{
    return (top == -1);
}

template <class T>
int GenStackGeneric<T>::getSize() //returns the size of the stack
{
    return top-1;
}
