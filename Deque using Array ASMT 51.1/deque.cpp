#include <iostream>
using namespace std;
class deque
{
private:
    int capacity;
    int front;
    int rear;
    int *ptr;

public:
    // Constructor
    deque() : front(-1), rear(-1), capacity(0), ptr(nullptr) {}

    deque(int capacity)
    {
        this->capacity = capacity;
        front = -1;
        rear = -1;
        ptr = new int[capacity];
    }

    void createArray(int capacity)
    {
        if (ptr != nullptr)
        {
            delete[] ptr;
            ptr = nullptr;
        }

        this->capacity = capacity;
        front = -1;
        rear = -1;
        ptr = new int[capacity];
    }

    // Distructor
    ~deque()
    {
        delete[] ptr;
        ptr = nullptr;
    }

    // Copy constructor to implement deep copy
    deque(deque &other)
    {
        ptr = nullptr;
        capacity = other.capacity;
        front = other.front;
        rear = other.rear;ptr = new int[capacity];

        if (other.front == 0)
        {
            for (int i = other.front; i <= other.rear; i++)
                ptr[i] = other.ptr[i];
        }

        if (other.front > 0 && other.rear > other.front)
        {
            for (int i = other.front; i <= other.rear; i++)
                ptr[i] = other.ptr[i];
        }

        if (other.front > 0 && other.rear < other.front)
        {
            for (int i = other.front; i < other.capacity; i++)
                ptr[i] = other.ptr[i];

            for (int i = 0; i <= other.rear; i++)
                ptr[i] = other.ptr[i];
        }
    }

    // Copy assignment operator to implement deep copy
    deque &operator=(deque &other)
    {
        capacity = other.capacity;
        front = other.front;
        rear = other.rear;
        ptr = new int[capacity];

        if (other.front == 0)
        {
            for (int i = other.front; i <= other.rear; i++)
                ptr[i] = other.ptr[i];
        }

        if (other.front > 0 && other.rear > other.front)
        {
            for (int i = other.front; i <= other.rear; i++)
                ptr[i] = other.ptr[i];
        }

        if (other.front > 0 && other.rear < other.front)
        {
            for (int i = other.front; i < other.capacity; i++)
                ptr[i] = other.ptr[i];

            for (int i = 0; i <= other.rear; i++)
                ptr[i] = other.ptr[i];
        }

        return *this;
    }

    // Method to insert an element at front
    void insertFront(int);

    // Method to insert an element at rear
    void insertRear(int);

    // Method to delete front element
    void deleteFront();

    // Method to delete rear element
    void deleteRear();

    // Method to print list
    void displayList();

    // Method to print front element
    void frontElement();

    // Method to print rear element
    void rearElement();

    // Method to check array is empty or not
    void is_empty();
};

void deque::insertFront(int element)
{
    if (front == -1)
    {
        ptr[++front] = element;
        rear = front;
    }
    else if (front == 0 && rear != capacity - 1)
    {
        int i = rear + 1;
        while (i > 0)
        {
            ptr[i] = ptr[i - 1];
            i--;
        }

        ptr[i] = element;
        front = i;
        rear++;
    }
    else if (front > 0 && front != rear + 1)
    {
        if (front != 0)
            ptr[--front] = element;
    }
    else
        cout << "Array is full";
}

void deque::insertRear(int element)
{
    if (rear == -1)
    {

        ptr[++rear] = element;
        front = rear;
    }
    else if (front == 0 && rear != capacity - 1)
        ptr[++rear] = element;
    else if (front > 0 && front != rear + 1)
    {
        if (rear == capacity - 1)
            rear = -1;
        ptr[++rear] = element;
    }
    else
        cout << "Array is full";
}

void deque::deleteFront()
{
    if (rear == -1)
        cout << "Array is empty";
    else if (rear == front)
    {
        rear = -1;
        front = -1;
    }
    else
        front++;
}

void deque::deleteRear()
{
    if (rear == -1)
        cout << "Array is empty";
    else if (rear == front)
    {
        rear = -1;
        front = -1;
    }
    else
        rear--;
}

void deque::displayList()
{
    if (rear == -1 && front == -1)
    {
        cout << "Array is empty";
        return;
    }

    if (front == 0)
    {
        for (int i = front; i <= rear; i++)
            cout << ptr[i] << " ";
    }

    if (front > 0 && rear > front)
    {
        for (int i = front; i <= rear; i++)
            cout << ptr[i] << " ";
    }

    if (front > 0 && rear < front)
    {
        for (int i = front; i <capacity; i++)
            cout << ptr[i] << " ";

        for (int i = 0; i <= rear; i++)
            cout << ptr[i] << " ";
    }
}

void deque::frontElement()
{
    if (rear == -1 && front == -1)
        cout << "Array is empty";
    else
        cout << "Front element: " << ptr[front];
}

void deque::rearElement()
{
    if (rear == -1 && front == -1)
        cout << "Array is empty";
    else
        cout << "Rear element: " << ptr[rear];
}

void deque::is_empty()
{
    if (front == -1 && rear == -1)
    {
        cout << "Arra is empty";
        return;
    }
    else
        cout << "Array is not empty";
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
    obj.createArray(5);

    obj.insertFront(5);
    obj.insertFront(4);
    obj.insertFront(3);
    obj.insertFront(2);
    obj.insertFront(1);
    // while (true)
    // {
    //     switch (menu())
    //     {
    //     case 1:
    //         int data;
    //         cout << "Enter element: ";
    //         cin >> data;
    //         obj.insertFront(data);
    //         break;

    //     case 2:
    //         int Data;
    //         cout << "Enter element: ";
    //         cin >> Data;
    //         obj.insertRear(Data);
    //         break;

    //     case 3:
    //         obj.deleteFront();
    //         break;

    //     case 4:
    //         obj.deleteRear();
    //         break;

    //     case 5:
    //         obj.displayList();
    //         break;

    //     case 6:
    //         obj.frontElement();
    //         break;

    //     case 7:
    //         obj.rearElement();
    //         break;

    //     case 8:
    //         obj.is_empty();
    //         break;

    //     case 9:
    //         cout << "Program has been ended!";
    //         exit(0);

    //     default:
    //         cout << "Invalid Choice";
    //         break;
    //     }
    // }

    deque d = obj;
    d.displayList(); 

    return 0;
}