#include <iostream>
using namespace std;
struct node
{
    node *prev;
    int item;
    node *next;
};

class deque
{
private:
    node *front;
    node *rear;

public:
    // Constructor
    deque() : front(nullptr), rear(nullptr) {}

    // Distructor
    ~deque()
    {
        while (front)
            deleteFront();
    }

    // Copy constructor to implement deep copy
    deque(deque &other)
    {
        if (other.front == nullptr)
            front = rear = nullptr;
        else
        {
            node *temp = other.front;
            while (temp)
            {
                insertRear(temp->item);
                temp = temp->next;
            }
        }
    }

    // Copy assignment operator to implement deep copy
    deque &operator=(deque &other)
    {
        while (front)
            deleteFront();

        if (other.front == nullptr)
            front = rear = nullptr;
        else
        {
            node *temp = other.front;
            while (temp)
            {
                insertRear(temp->item);
                temp = temp->next;
            }
        }

        return *this;
    }

    // Method to insert an element at front of list
    void insertFront(int);

    // Method to insert an element at rear of list
    void insertRear(int);

    // Method to delete front element/node of list
    void deleteFront();

    // Method to delete rear element/node of list
    void deleteRear();

    // Method to print list
    void displayList();

    // Method to print front element
    void frontElement();

    // Method to print rear element
    void rearElement();

    // Method to check list is empty or not
    void checkList();
};

void deque::insertFront(int element)
{
    node *newNode = new node;
    newNode->item = element;

    if (front == nullptr)
    {
        front = newNode;
        rear = newNode;

        newNode->prev = nullptr;
        newNode->next = nullptr;
    }
    else
    {
        newNode->prev = nullptr;
        newNode->next = front;
        front->prev = newNode;
        rear = front;
        front = newNode;
    }
}

void deque::insertRear(int element)
{
    node *newNode = new node;
    newNode->item = element;

    if (rear == nullptr)
    {
        rear = newNode;
        front = newNode;
        newNode->prev = nullptr;
        newNode->next = nullptr;
    }
    else
    {
        rear->next = newNode;
        newNode->prev = rear;
        newNode->next = nullptr;
        rear = newNode;
    }
}

void deque::deleteFront()
{
    if (front == nullptr || rear == nullptr)
    {
        cout << "List is empty";
        return;
    }
    node *temp = front;
    front = front->next;
    front->prev = nullptr;
    temp->next = nullptr;

    delete temp;
    temp = nullptr;
}

void deque::deleteRear()
{
    if (front == nullptr && rear == nullptr)
    {
        cout << "List is empty";
        return;
    }
    else if (front == rear)
    {
        delete front;
        front = nullptr;
        rear = nullptr;

        checkList();
        return;
    }
    node *temp = rear;
    rear = rear->prev;
    rear->next = nullptr;
    temp->prev = nullptr;

    delete temp;
    temp = nullptr;
    displayList();
}

void deque::displayList()
{
    if (front == nullptr && rear == nullptr)
    {
        cout << "List is empty";
        return;
    }
    node *print = front;
    while (print)
    {
        cout << print->item << " ";
        print = print->next;
    }
}

void deque::frontElement()
{
    if (front == nullptr && rear == nullptr)
    {
        cout << "List is empty";
        return;
    }
    cout << "Front element: " << front->item;
}

void deque::rearElement()
{
    if (front == nullptr && rear == nullptr)
    {
        cout << "List is empty";
        return;
    }
    cout << "Rear element: " << rear->item;
}

void deque::checkList()
{
    if (front == nullptr && rear == nullptr)
        cout << "List is empty";
    else
        cout << "List is not empty";
}

int menu()
{
    int choice;
    cout << endl
         << endl
         << "1.Insert an element at front" << endl;
    cout << "2.Insert an element at rear" << endl;
    cout << "3.Delete front element" << endl;
    cout << "4.Delete rear element" << endl;
    cout << "5.Display deque" << endl;
    cout << "6.Get front element" << endl;
    cout << "7.Get rear element" << endl;
    cout << "8.Check deque" << endl;
    cout << "9.Exit program" << endl
         << endl;

    cout << "Enter your choice: ";
    cin >> choice;

    return choice;
}

int main()
{
    deque obj;
    while (true)
    {
        switch (menu())
        {
        case 1:
            int data;
            cout << "Enter element: ";
            cin >> data;
            obj.insertFront(data);
            break;

        case 2:
            int Data;
            cout << "Enter element: ";
            cin >> Data;
            obj.insertRear(Data);
            break;

        case 3:
            obj.deleteFront();
            break;

        case 4:
            obj.deleteRear();
            break;

        case 5:
            obj.displayList();
            break;

        case 6:
            obj.frontElement();
            break;

        case 7:
            obj.rearElement();
            break;

        case 8:
            obj.checkList();
            break;

        case 9:
            cout << "Program has been ended!";
            exit(0);

        default:
            cout << "Invalid Choice";
            break;
        }
    }

    return 0;
}