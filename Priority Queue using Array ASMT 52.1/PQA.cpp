#include <iostream>
using namespace std;
struct node
{
    int priority;
    int element;
};

class PQ
{
private:
    int capacity;
    int rear;
    int front;
    node *ptr;

public:
    PQ() : capacity(0), rear(-1), front(-1), ptr(nullptr) {}

    PQ(int capacity)
    {
        this->capacity = capacity;
        front = -1;
        rear = -1;
        ptr = new node[capacity];
    }

    PQ(PQ &other)
    {
        capacity = other.capacity;
        front = other.front;
        rear = other.rear;
        ptr = new node[capacity];
        for(int i=other.front; i<=other.rear; i++)
            ptr[i] = other.ptr[i];
    }

    PQ& operator=(PQ &other)
    {
        if(ptr!=nullptr)
        {
            delete []ptr;
            ptr = nullptr;
        }
        
        capacity = other.capacity;
        front = other.front;
        rear = other.rear;
        ptr = new node[capacity];
        for(int i=other.front; i<=other.rear; i++)
            ptr[i] = other.ptr[i];

        return *this;
    }

    void createPQ(int capacity)
    {
        if (ptr != nullptr)
        {
            delete[] ptr;
            ptr = nullptr;
        }

        this->capacity = capacity;
        front = -1;
        rear = -1;
        ptr = new node[capacity];
    }

    void insertElement(int priority, int element)
    {
        if (front == -1)
        {
            ptr[front + 1].priority = priority;
            ptr[front + 1].element = element;
            rear++;
            front++;
        }
        else if (rear != capacity - 1)
        {
            bool b = false;
            for (int i = front; i <= rear; i++)
            {
                if (priority >= ptr[i].priority)
                {
                    b = true;
                    if (priority == ptr[i].priority)
                        i++;

                    int j = rear + 1;
                    while (j >= i)
                    {
                        ptr[j] = ptr[j - 1];
                        j--;
                    }

                    ptr[i].priority = priority;
                    ptr[i].element = element;
                    rear++;
                    break;
                }
            }

            if (b == false)
            {
                ptr[rear + 1].priority = priority;
                ptr[rear + 1].element = element;
                rear++;
            }
        }
    }

    void displayElement()
    {
        for (int i = front; i <= rear; i++)
        {
            cout << ptr[i].priority << " " << ptr[i].element << endl;
        }
    }

    void deleteElement()
    {
        int i = 1;
        while (i <= rear)
        {
            ptr[i - 1] = ptr[i];
            i++;
        }
        rear--;
    }

    ~PQ()
    {
        delete []ptr;
        ptr = nullptr;
    }
};

int main()
{
    PQ obj;
    obj.createPQ(10);
    obj.insertElement(120, 12);
    obj.insertElement(110, 11);
    obj.insertElement(100, 10);
    obj.insertElement(90, 9);
    obj.insertElement(80, 8);
    obj.insertElement(70, 7);
    obj.insertElement(130, 13);
    obj.insertElement(60, 6);
    obj.insertElement(95, 55);
    obj.insertElement(90,66);
    //obj.deleteElement();
    //obj.displayElement();

    PQ O;
    O = obj;
    O.displayElement();

    return 0;
}
