#include <iostream>
using namespace std;
template <typename T>
class Queue
{
private:
    int capacity;
    int front;
    int rear;
    T *ptr;

public:
    // Default constructor to initialize instance member variable
    Queue() : capacity(0), front(-1), rear(-1), ptr(nullptr) {}

    // Parameterized constructor to initialize instance member variable
    Queue(int capacity)
    {
        this->capacity = capacity;
        front = -1;
        rear = -1;
        ptr = new T[capacity];
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
            ptr = new T[other.capacity];
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
            ptr = new T[other.capacity];
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
    void insertElement(T);

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

template <typename T>
void Queue<T>::createQueue(int capacity)
{
    if (ptr != nullptr)
    {
        delete ptr;
        ptr = nullptr;
    }

    this->capacity = capacity;
    front = -1;
    rear = -1;
    ptr = new T[capacity];
}

template <typename T>
void Queue<T>::insertElement(T element)
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

template <typename T>
void Queue<T>::deleteFront()
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

template <typename T>
void Queue<T>::displayQueue()
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

template <typename T>
void Queue<T>::rearElement()
{
    cout << "Rear element: " << ptr[rear];
}

template <typename T>
void Queue<T>::frontElement()
{
    cout << "Front element: " << ptr[front];
}

template <typename T>
void Queue<T>::checkOverflow()
{
    if ((front == 0 && rear == capacity-1) || (front > 0 && rear == front-1))
    {
        cout << "Now, Queue overflow";
    }
    else
        cout << "Queue is not overflow";
}

template <typename T>
void Queue<T>::checkUnderflow()
{
    if (front == -1)
        cout << "Queue underflow";
    else
        cout << "Queue is not underflow";
}

template <typename T>
void Queue<T>::countElement()
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

int main()
{
    Queue <int>obj;
    obj.createQueue(5);
    obj.insertElement(5);
    obj.insertElement(6);
    obj.insertElement(7);
    obj.insertElement(8);
    obj.insertElement(9);
    obj.displayQueue();
    return 0;
}