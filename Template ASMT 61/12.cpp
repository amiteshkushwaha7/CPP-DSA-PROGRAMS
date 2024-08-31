#include<iostream>
using namespace std;
template <typename T>
struct node
{
    node<T> *prev;
    T item;
    node<T> *next;
};

template <typename T>
class STACK
{
    private:
        node<T> *start;
        node<T> *top;
    
    public:
        //Constructor to initialize instance variables
        STACK()
        {
            start = nullptr;
            top = nullptr;
        }

        //Destructor to deallocated stack memory
        ~STACK()
        {
            while (start != nullptr)
                popElement();

            start = nullptr;
            top = nullptr;               
        }

        //Copy constructor to implement deep copy
        STACK(STACK &other)
        {
            if(other.start == nullptr)
            {
                start = nullptr;
                top = nullptr;
            }
            else
            {
                node<T> *temp = other.start;
                while (temp->next != nullptr)
                {
                    pushElement(temp->item);
                    temp = temp->next;
                }
                pushElement(temp->item); 

            }  
        }

        //Copy assignment operator to implement deep copy
        STACK& operator=(STACK &other)
        {
            while(start!=nullptr || top!=nullptr)
                popElement();

            if(other.start == nullptr)
            {
                start = nullptr;
                top = nullptr;
            }
            else
            {
                node<T> *temp = other.start;
                while (temp->next != nullptr)
                {
                    pushElement(temp->item);
                    temp = temp->next;
                }
                pushElement(temp->item); 
            }
            return *this;
        }

        //Method to insert new element in the stack
        void pushElement(T);

        //Method to peek top element of the stack
        T peekElement();

        //Method to pop the top element of the stack
        void popElement();

        //Method to print stack
        void displayStack();

        //Method to reverse stack
        void reverseStack();
};

template <typename T>
void STACK<T>::pushElement(T element)
{
    node<T> *newNode = new node<T>;
    newNode->item = element;

    if(start == nullptr)
    {
        start = newNode;
        start->prev = nullptr;
        start->next = nullptr;
        top = start;
    }  
    else
    {
        top->next = newNode;
        newNode->prev = top;
        newNode->next = nullptr;
        top = newNode;
    }
}

template <typename T>
T STACK<T>::peekElement()
{
    if(start == nullptr)
        return T();
    return top->item; 
}

template <typename T>
void STACK<T>::popElement()
{
    if(start == nullptr)
        cout<<"Stack is underflow";
    else if(start->prev == start->next)
    {
        delete start;
        start = nullptr;
    }
    else
    {
        node<T> *temp = top;
        top = top->prev;
        top->next = nullptr;

        temp->prev = nullptr; 
        delete temp;
        temp = nullptr;
    } 
}

template <typename T>
void STACK<T>::displayStack()
{
    if(start == nullptr)
        cout<<"Stack is underflow";
    else
    {
        node<T> *print = top;
        while(print->prev != nullptr)
        {
            cout<<print->item <<" ";
            print = print->prev;
        }
        cout<<print->item;

        print = nullptr;
    }
}

template <typename T>
void STACK<T>::reverseStack()
{
    if(start == nullptr)
        cout<<"Stack is underflow";
    else
    {
        STACK <T>temp;
        while(top != start)
        {
            temp.pushElement(top->item);
            popElement();
        }
        temp.pushElement(top->item);
        popElement();

        node<T> *t = temp.start;
        while(t != nullptr)
        {
            pushElement(t->item);
            t = t->next;
        }

        temp.~STACK();
    }
}

int main()
{
    STACK <string>obj;
    obj.pushElement("AAA");
    obj.pushElement("VVVV");
    obj.displayStack();
    return 0;
}