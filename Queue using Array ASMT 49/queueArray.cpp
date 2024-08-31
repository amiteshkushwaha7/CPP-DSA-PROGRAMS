#include <iostream>
using namespace std;
class Queue
{
private:
    int capacity;
    int front;
    int rear;
    int *ptr;

public:
    // Default constructor to initialize instance member variable
    Queue() : capacity(0), front(-1), rear(-1), ptr(nullptr) {}

    // Parameterized constructor to initialize instance member variable
    Queue(int capacity)
    {
        this->capacity = capacity;
        front = -1;
        rear = -1;
        ptr = new int[capacity];
    }

    // Distructor
    ~Queue()
    {
        delete[] ptr;
        ptr = nullptr;
    }

    // Copy constructor to implement deep copy
    Queue(Queue &other)
    {
        capacity = other.capacity;
        front = other.front;
        rear = other.rear;
        if (other.ptr == nullptr)
            ptr = nullptr;
        else
        {
            ptr = new int[other.capacity];
            if (rear > front)
            {
                for (int i = front; i < rear; i++)
                    ptr[i] = other.ptr[i];
            }
            else
            {
                for (int i = front; i < capacity; i++)
                    ptr[i] = other.ptr[i];

                for (int i = 0; i < rear; i++)
                    ptr[i] = other.ptr[i];
            }
        }
    }

    // Copy assignment operator to implement deep copy
    Queue &operator=(Queue &other)
    {
        delete[] ptr;
        capacity = other.capacity;
        front = other.front;
        rear = other.rear;

        if (other.ptr == nullptr)
            ptr = nullptr;
        else
        {
            ptr = new int[other.capacity];
            if (rear > front)
            {
                for (int i = front; i < rear; i++)
                    ptr[i] = other.ptr[i];
            }
            else
            {
                for (int i = front; i < capacity; i++)
                    ptr[i] = other.ptr[i];

                for (int i = 0; i < rear; i++)
                    ptr[i] = other.ptr[i];
            }
        }
        return *this;
    }

    // Method to create Queue
    void createQueue(int);

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

    // Method to check Queue overflow
    void checkOverflow();

    // Method to check Queue underflow
    void checkUnderflow();

    // Method to count total queue element
    void countElement();
};

void Queue::createQueue(int capacity)
{
    if (ptr != nullptr)
    {
        delete ptr;
        ptr = nullptr;
    }

    this->capacity = capacity;
    front = -1;
    rear = -1;
    ptr = new int[capacity];
}

void Queue::insertElement(int element)
{
    if ((front == 0 && rear == capacity-1) || (front > 0 && rear == front-1))
    {
        cout << "Now, Queue overflow";
        return;
    }

    if (front == -1)
    {
        front = 0;
        rear = 0;
        ptr[rear] = element;
    }
    else if(rear == capacity-1)
    {
        rear = 0;
        ptr[rear] = element;
    }
    else
    {
        rear++;
        ptr[rear] = element;
    }
}

void Queue::deleteFront()
{
    if (rear == -1 && front == -1)
        cout << "Queue underflow";
    else if (front == rear)
    {
        front = -1;
        rear = -1;
        cout << "Now, Queue underflow";
    }
    else
    {
        ++front;
        if (front == capacity)
            front = 0;

        // displayQueue();
    }
}

void Queue::displayQueue()
{
    if (front == -1)
    {
        cout << "Queue underflow";
        return;
    }

    if (rear > front)
    {
        for (int i = front; i <= rear; i++)
            cout << ptr[i] << " ";
    }
    else
    {
        for (int i = front; i < capacity; i++)
            cout << ptr[i] << " ";

        for (int i = 0; i <= rear; i++)
            cout << ptr[i] << " ";
    }
}

void Queue::rearElement()
{
    cout << "Rear element: " << ptr[rear];
}

void Queue::frontElement()
{
    cout << "Front element: " << ptr[front];
}

void Queue::checkOverflow()
{
    if ((front == 0 && rear == capacity-1) || (front > 0 && rear == front-1))
    {
        cout << "Now, Queue overflow";
    }
    else
        cout << "Queue is not overflow";
}

void Queue::checkUnderflow()
{
    if (front == -1)
        cout << "Queue underflow";
    else
        cout << "Queue is not underflow";
}

void Queue::countElement()
{
    if (front == -1)
        cout << "Queue underflow";
    else
    {
        int i = front, cnt = 0;
        while (i != rear)
        {
            cnt++;
            i++;
        }
        cnt++;
        cout << cnt;
    }
}

int menu()
{
    int choice;
    cout << endl
         << endl
         << "1.Create queue" << endl;
    cout << "2.Insert an element" << endl;
    cout << "3.Delete an element" << endl;
    cout << "4.Display queue" << endl;
    cout << "5.Display rear element" << endl;
    cout << "6.Display front element" << endl;
    cout << "7.Check overflow" << endl;
    cout << "8.Check underflow" << endl;
    cout << "9.Count total queue's element" << endl;
    cout << "10.Exit program" << endl
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
            int capacity;
            cout << "Enter the capacity of array: ";
            cin >> capacity;
            obj.createQueue(capacity);
            break;

        case 2:
            int data;
            cout << "Enter element: ";
            cin >> data;
            obj.insertElement(data);
            break;

        case 3:
            obj.deleteFront();
            break;

        case 4:
            obj.displayQueue();
            break;

        case 5:
            obj.rearElement();
            break;

        case 6:
            obj.frontElement();
            break;

        case 7:
            obj.checkOverflow();
            break;

        case 8:
            obj.checkUnderflow();
            break;

        case 9:
            obj.countElement();
            break;

        case 10:
            cout << "Program has been ended!";
            exit(0);

        default:
            cout << "Invalid Choice";
            break;
        }
    }

    return 0;
}