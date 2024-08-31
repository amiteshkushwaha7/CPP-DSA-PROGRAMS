#include <iostream>
using namespace std;
class ARRAY
{
private:
    int capacity;
    int front;
    int rear;
    int *ptr;

public:
    ARRAY() : capacity(0), front(-1), rear(0), ptr(nullptr) {}

    ARRAY(int capacity)
    {
        this->capacity = capacity;
        front = -1;
        rear = -1;
        ptr = new int[capacity];
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
        ptr = new int[capacity];
    }

    ~ARRAY()
    {
        delete []ptr;
        ptr = nullptr;
    }

    // Copy constructor to implement deep copy
    ARRAY(ARRAY &other)
    {
        capacity = other.capacity;
        front = other.front;
        rear = other.rear;
        ptr = new int[capacity];

        for(int i=other.front; i<=other.rear; i++)
            ptr[i] = other.ptr[i];
    }

    // Copy assignment operator to implement deep copy
    ARRAY &operator=(ARRAY &other)
    {
        if(ptr!=nullptr)
        {
            delete ptr;
            ptr = nullptr
        }
         
        capacity = other.capacity;
        front = other.front;
        rear = other.rear;
        ptr = new int[capacity];

        for(int i=other.front; i<=other.rear; i++)
            ptr[i] = other.ptr[i];

        return *this;
    }

    // Method to insert new item in list
    void insertElement(int element)
    {
        if(rear == -1)
        {
            ptr[++rear] = element;
            front = rear;
        }
        else if(rear!=capacity-1)
            ptr[++rear] = element;
        else
            cout<<"Array is full";
    }

    // Method to delete highest priority node
    void deleteElement()
    {
        if(front -1 && rear == -1)
        {
            cout<<"All element deleted";
            return;
        }

        int i = front+1;
        while(i<=rear)
        {
            ptr[i-1] = ptr[i];
            i++;
        }

        rear--;
    }

    // Method to print list
    void displayArray()
    {
        if(front -1 && rear == -1)
        {
            cout<<"All element deleted";
            return;
        }

        for(int i=front; i<=rear; i++)
            cout<<ptr[i]<<" ";
    }

    // Method to get highest priority element
    int getElement()
    {
        return ptr[front];
    }

    // Method to check list is empty
    void checkArray()
    {
        if(front == -1 && rear == -1)
            cout<<"Array is empty";
        else
            cout<<"Array is not empty";
    }
};
 
class Priority
{
    private:
        int priCapacity;
        ARRAY *priorityArray;
    
    public:
        Priority():priCapacity(0),priorityArray(nullptr){}

        Priority(Priority &other)
        {
            priCapacity = other.priCapacity;
            priorityArray = new ARRAY*[priCapacity];
            for(int i=0; i<priCapacity; i++)
                priorityArray[i] = other.priorityArray[i];
        }

        Priority& operator=(Priority &other)
        {
            if(priorityArray!=nullptr)
                ~Priority();

            priCapacity = other.priCapacity;
            priorityArray = new ARRAY*[priCapacity];
            for(int i=0; i<priCapacity; i++)
                priorityArray[i] = other.priorityArray[i];

            return *this;
        }

        Priority(int priCapacity)
        {
            this->priCapacity = priCapacity;
            priorityArray = new ARRAY*[priCapacity];
        }

        void createPriorityArray(int priCapacity)
        {
            if(priorityArray != nullptr)
            {
                for(int i=0; i<priCapacity; i++)
                    priorityArray[i].~ARRAY();

                priorityArray = nullptr;
            }

            this->priCapacity = priCapacity;
            priority = new ARRAY*[priCapacity];
        }

        void insertPriority()
        {
            int n,size;
            for(int i=0; i<priCapacity; i++)
            {
                cout<<"Enter priority,array size of this priority:";
                cin>>n>>size;
                priorityArray[i] = n;
                priorityArray[i].createPQ(size); 
            }
        }

        void insertElement(int priority, int element)
        {
            for(int i=0; i<priCapacity; i++)
            {
                if(priorityArray[i]==priority)
                {
                    priorityArray[i].insertElement(element);
                    return;
                }
            }
            cout<<"Invalid priority";
        }

        ~Priority()
        {
            for(int i=0; i<priCapacity; i++)
                priorityArray[i].~ARRAY();

            delete []priorityArray;
            priorityArray = nullptr;
        }
};

int main()
{
    Priority obj;
    obj.createPriorityArray(5);
    obj.insertPriority();
    obj.insertElement()

    return 0;
}