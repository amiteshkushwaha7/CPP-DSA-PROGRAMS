#include <iostream>
using namespace std;
struct node
{
    int item;
    node *next;
};

class Queue
{
private:
    node *front;
    node *rear;

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
        node *temp = other.front;
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

        node *temp = other.front;
        while (temp != nullptr)
        {
            insertElement(temp->item);
            temp = temp->next;
        }
        return *this;
    }

    // Method to insert a element in Queue
    void insertElement(int);

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

void Queue::insertElement(int element)
{
    node *newNode = new node;
    newNode->item = element;

    if (rear == nullptr)
    {
        front = newNode;
        rear = newNode;
        rear->next = nullptr;
    }
    else
    {
        node *temp = front;
        while(temp->next != nullptr)
            temp = temp->next;

        temp->next = newNode;
        rear = newNode;
        newNode->next = nullptr;
    }
}

void Queue::deleteFront()
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
        node *temp = front;
        front = front->next;
        temp->next = nullptr;

        delete temp;
        temp = nullptr;

        displayQueue();
    }
}

void Queue::displayQueue()
{
    if (rear == nullptr)
        cout << "Queue is underflow";
    else
    {
        node *print = front;
        while (print != nullptr)
        {
            cout << print->item << " ";
            print = print->next;
        }
        print = nullptr;
    }
}

void Queue::frontElement()
{
    if (rear == nullptr)
        cout << "Queue underflow";
    else
        cout << "Front element: " << front->item;
}

void Queue::rearElement()
{
    if (rear == nullptr)
        cout << "Queue underflow";
    else
        cout << "Rear element: " << rear->item;
}

void Queue::countElement()
{
    int cnt = 0;
    node *temp = front;
    while (temp != nullptr)
    {
        cnt++;
        temp = temp->next;
    }

    cout << "Total element: " << cnt;
}

int menu()
{
    int choice;
    cout << endl
         << endl
         << "1.Insert an element" << endl;
    cout << "2.Delete an element" << endl;
    cout << "3.Display queue" << endl;
    cout << "4.Display rear element" << endl;
    cout << "5.Display front element" << endl;
    cout << "6.Count total queue's element" << endl;
    cout << "7.Exit program" << endl
         << endl;

    cout << "Enter your choice: ";
    cin >> choice;

    return choice;
}

int main()
{
    Queue obj;
    while (true)
    {
        switch (menu())
        {
        case 1:
            int data;
            cout << "Enter element: ";
            cin >> data;
            obj.insertElement(data);
            break;

        case 2:
            obj.deleteFront();
            break;

        case 3:
            obj.displayQueue();
            break;

        case 4:
            obj.rearElement();
            break;

        case 5:
            obj.frontElement();
            break;

        case 6:
            obj.countElement();
            break;

        case 7:
            cout << "Program has been ended!";
            exit(0);

        default:
            cout << "Invalid Choice";
            break;
        }
    }

    return 0;
}