#include<iostream>
using namespace std;
template <typename T>
class STACK
{
    private:
        int capacity;
        int top;
        T *ptr;

    public:
        //Constructor to initialize instance variables
        STACK()
        {
            this->capacity = 0;
            this->top = -1;

            ptr = nullptr; //Allocate memory for dynamic array
        }

        //Parameterized Constructor to initialize instance variables
        STACK(int capacity)
        {
            this->capacity = capacity;
            this->top = -1;

            ptr = new T[capacity]; //Allocate memory for dynamic array
        }

        //Method to create stack
        void createStack(int capacity)
        {
            if(ptr!=nullptr)
            {
                delete[] ptr;
                ptr = nullptr;
            }
            this->capacity = capacity;
            top = -1;
            ptr = new T[capacity];
        }

        //Destructor to deallocated stack memory
        ~STACK()
        {
            delete[] ptr;
            ptr = nullptr;
        }

        //Copy constructor to implement deep copy
        STACK(STACK &other)
        {
            capacity = other.capacity;
            top = other.top;

            ptr = new T[capacity];
            for(int i=0; i<=other.top; i++)
            ptr[i] = other.ptr[i];
        }

        //Copy assignment operator to implement deep copy
        STACK& operator=(STACK &other)
        {
            delete[] ptr;
            ptr = nullptr;

            capacity = other.capacity;
            top = other.top;

            ptr = new T[capacity];
            for(int i=0; i<=other.top; i++)
            ptr[i] = other.ptr[i];
            
            return *this;
        }

        //Method to insert new element in the stack
        void pushElement(T);

        //Method to double the size of array
        void doubleArray();

        //Method to half the size of array
        void halfArray();

        //Method to peek top element of the stack
        T peekElement();

        //Method to pop the top element of the stack
        void popElement();

        //Metho to check stack overflow
        void checkOverflow();

        //Method to check stack underflow
        void checkUnderflow();

        //Method to print stack
        void displayStack();

        //Method to return current array capacity
        int returnTop();
        
        //Method to return array capacity
        int returnCapacity();
};

template <typename T>
void STACK<T>::pushElement(T element)
{
    if(top == (capacity-1))
        cout<<"Stack overflow";
    else
    {
        top++;
        ptr[top] = element;
    }
}

template <typename T>
void STACK<T>::doubleArray()
{
    int *temp = new T[capacity*2];
    for(int i=0; i<=top; i++)
        temp[i] = ptr[i];
    
    delete[] ptr;
    ptr = temp;
    capacity = capacity*2;

    delete[] temp;
    temp = nullptr;
    cout<<"Array has been doubled";
}

template <typename T>
void STACK<T>::halfArray()
{
    int *temp = new T[(capacity/2)+1];
    for(int i=0; i<=top; i++)
        temp[i] = ptr[i];
    
    delete[] ptr;
    ptr = temp;
    capacity = (capacity/2) + 1;

    delete[] temp;
    temp = nullptr;
    cout<<"Array has been halfed";
}

template <typename T>
T STACK<T>::peekElement()
{
    if(top == -1)
        return 0;
    return ptr[top];
}

template <typename T>
void STACK<T>::popElement()
{
    if(top == -1)
        cout<<"Stack is underflow";
    else
        --top;
}

template <typename T>
void STACK<T>::checkOverflow()
{
    if(top == (capacity-1))
        cout<<"Stack overflow";
    else
        cout<<"Stack is not overflow";
}

template <typename T>
void STACK<T>::checkUnderflow()
{
    if(top == -1)
        cout<<"Stack underflow";
    else
        cout<<"Stack is not underflow";
}

template <typename T>
void STACK<T>::displayStack()
{
    for(int printIndex = top; printIndex>=0; printIndex--)
            cout<<ptr[printIndex] <<" ";
}

template <typename T>
int STACK<T>::returnTop()
{
    return top;
}

template <typename T>
int STACK<T>::returnCapacity()
{
    return capacity;
}

int main()
{
    STACK <int>obj;
    obj.createStack(3);
    obj.pushElement(10);
    obj.pushElement(20);
    obj.pushElement(30);
    obj.displayStack();
    return 0;
}