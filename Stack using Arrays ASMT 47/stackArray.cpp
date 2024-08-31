#include<iostream>
using namespace std;
class STACK
{
    private:
        int capacity;
        int top;
        int *ptr;

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

            ptr = new int[capacity]; //Allocate memory for dynamic array
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
            ptr = new int[capacity];
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

            ptr = new int[capacity];
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

            ptr = new int[capacity];
            for(int i=0; i<=other.top; i++)
            ptr[i] = other.ptr[i];
            
            return *this;
        }

        //Method to insert new element in the stack
        void pushElement(int);

        //Method to double the size of array
        void doubleArray();

        //Method to half the size of array
        void halfArray();

        //Method to peek top element of the stack
        int peekElement();

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

void STACK::pushElement(int element)
{
    if(top == (capacity-1))
        cout<<"Stack overflow";
    else
    {
        top++;
        ptr[top] = element;
    }
}

void STACK::doubleArray()
{
    int *temp = new int[capacity*2];
    for(int i=0; i<=top; i++)
        temp[i] = ptr[i];
    
    delete[] ptr;
    ptr = temp;
    capacity = capacity*2;

    delete[] temp;
    temp = nullptr;
    cout<<"Array has been doubled";
}

void STACK::halfArray()
{
    int *temp = new int[(capacity/2)+1];
    for(int i=0; i<=top; i++)
        temp[i] = ptr[i];
    
    delete[] ptr;
    ptr = temp;
    capacity = (capacity/2) + 1;

    delete[] temp;
    temp = nullptr;
    cout<<"Array has been halfed";
}

int STACK::peekElement()
{
    if(top == -1)
        return 0;
    return ptr[top];
}

void STACK::popElement()
{
    if(top == -1)
        cout<<"Stack is underflow";
    else
        --top;
}

void STACK::checkOverflow()
{
    if(top == (capacity-1))
        cout<<"Stack overflow";
    else
        cout<<"Stack is not overflow";
}

void STACK::checkUnderflow()
{
    if(top == -1)
        cout<<"Stack underflow";
    else
        cout<<"Stack is not underflow";
}

void STACK::displayStack()
{
    for(int printIndex = top; printIndex>=0; printIndex--)
            cout<<ptr[printIndex] <<" ";
}

int STACK::returnTop()
{
    return top;
}

int STACK::returnCapacity()
{
    return capacity;
}

int menu()
{
    int choice;
    cout << endl << endl << "0.Create stack" << endl;
    cout << "1.Push new element in stack" << endl;
    cout << "2.Peek top element of the stack" << endl;
    cout << "3.Pop the top element of the stack" << endl;
    cout << "4.Check stack overflow" << endl;
    cout << "5.Check stack underflow" << endl;
    cout << "6.Display stack" << endl;
    cout << "7.Create double size array" << endl;
    cout << "8.Create half size array" << endl;
    cout << "9.Exit program" << endl << endl;

    cout << "Enter your choice: ";
    cin >> choice;

    return choice;
}

int main()
{
    STACK obj;
    while (true)
    {
        switch (menu())
        {
        case 0:
            int cap;
            cout<<"Enter stack capacity: ";
            cin>>cap;
            obj.createStack(cap);
            break;

        case 1:
            int data;
            cout << "Enter a data: ";
            cin >> data;
            obj.pushElement(data);
            break;

        case 2:
            int i;
            i = obj.peekElement();
            if(i==0)
                cout<<"Stack underflow";
            else
                cout<<"Stack's top = " <<obj.peekElement();
            break;

        case 3:
            obj.popElement();
            break;

        case 4:
            obj.checkOverflow();
            break;

        case 5:
            obj.checkUnderflow();
            break;

        case 6:
            cout<<"Stack elements: ";
            obj.displayStack();
            break;

        case 7:
            int TOP, CAPACITY;
            TOP = obj.returnTop();
            CAPACITY = obj.returnCapacity();

            if(TOP == (CAPACITY-1))
                obj.doubleArray();
            else
                cout<<"Failed: Current array is not full";
            break;
        
        case 8:
            int top, capacity;
            top = obj.returnTop();
            capacity = obj.returnCapacity();

            if(capacity/2 >= top+1)
                obj.halfArray();
            else
                cout<<"Failed: Current array has more number of element than half array size";
            break;

        case 9:
            cout << "Program has been ended!";
            exit(0);

        default:
            cout << "Invalid Choice";
            break;
        }
    }
}
