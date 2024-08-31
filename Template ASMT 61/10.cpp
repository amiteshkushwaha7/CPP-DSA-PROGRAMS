#include <iostream>
using namespace std;
template <typename T>
struct node
{
    T item;
    node<T> *next;
};

template <typename T>
class Queue
{
private:
    node<T> *front;
    node<T> *rear;

public:
    // Constructor to initialize instance variables
    Queue()
    {
        front = nullptr;
        rear = nullptr;
    }

    // Destructor to deallocated stack memory
    ~Queue()
    {
        while (front != nullptr)
            deleteFront();

        rear = nullptr;
        front = nullptr;
    }

    // // Copy constructor to implement deep copy
    Queue(Queue &other)
    {
        node<T> *temp = other.front;
        while (temp != nullptr)
        {
            insertElement(temp->item);
            temp = temp->next;
        }
    }

    // Copy assignment operator to implement deep copy
    Queue &operator=(Queue &other)
    {
        while (front != nullptr || rear != nullptr)
            deleteFront();

        node<T> *temp = other.front;
        while (temp != nullptr)
        {
            insertElement(temp->item);
            temp = temp->next;
        }
        return *this;
    }

    // Method to insert a element in Queue
    void insertElement(T);

    // Method to delete front element
    void deleteFront();

    // Method to display queue
    void displayQueue();

    // Method to get rear element
    void rearElement();

    // Method to get front element
    void frontElement();

    // Method to count total queue element
    void countElement();
};

template <typename T>
void Queue<T>::insertElement(T element)
{
    node<T> *newNode = new node<T>;
    newNode->item = element;

    if (rear == nullptr)
    {
        front = newNode;
        rear = newNode;
        rear->next = nullptr;
    }
    else
    {
        node<T> *temp = front;
        while(temp->next != nullptr)
            temp = temp->next;

        temp->next = newNode;
        rear = newNode;
        newNode->next = nullptr;
    }
}

template <typename T>
void Queue<T>::deleteFront()
{
    if (rear == nullptr)
        cout << "Queue is underflow";
    else if (rear == front)
    {
        front = nullptr;
        delete rear;
        rear = nullptr;

        displayQueue();
    }
    else
    {
        node<T> *temp = front;
        front = front->next;
        temp->next = nullptr;

        delete temp;
        temp = nullptr;

        displayQueue();
    }
}

template <typename T>
void Queue<T>::displayQueue()
{
    if (rear == nullptr)
        cout << "Queue is underflow";
    else
    {
        node<T> *print = front;
        while (print != nullptr)
        {
            cout << print->item << " ";
            print = print->next;
        }
        print = nullptr;
    }
}

template <typename T>
void Queue<T>::frontElement()
{
    if (rear == nullptr)
        cout << "Queue underflow";
    else
        cout << "Front element: " << front->item;
}

template <typename T>
void Queue<T>::rearElement()
{
    if (rear == nullptr)
        cout << "Queue underflow";
    else
        cout << "Rear element: " << rear->item;
}

template <typename T>
void Queue<T>::countElement()
{
    int cnt = 0;
    node<T> *temp = front;
    while (temp != nullptr)
    {
        cnt++;
        temp = temp->next;
    }

    cout << "Total element: " << cnt;
}
 
int main()
{
    Queue <string>obj;
    obj.insertElement("Aaaa");
    obj.insertElement("Bbb");
    obj.displayQueue();
    return 0;
}