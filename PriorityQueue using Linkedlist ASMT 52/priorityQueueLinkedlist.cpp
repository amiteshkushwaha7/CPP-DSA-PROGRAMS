#include<iostream>
using namespace std;
struct node
{
    int priority;
    int item;
    node *next;
};

class priorityQueue
{
private:
    node *start;

public:
    //Constructor
    priorityQueue():start(nullptr){}

    //Distructor
    ~priorityQueue ()
    {
        while(start != nullptr)
            deleteNode();
    }

    //Copy constructor to implement deep copy
    priorityQueue(priorityQueue &other)
    {
        start = new node;
        node *temp = other.start;
        while(temp)
        {
            insertElement(temp->item, temp->priority);
            temp = temp->next;
        }
    }

    //Copy assignment operator to implement deep copy
    priorityQueue& operator=(priorityQueue &other)
    {
        while(start)
            deleteNode();
        
        start = new node;
        node *temp = other.start;
        while(temp)
        {
            insertElement(temp->item, temp->priority);
            temp = temp->next;
        }

        return *this;
    }

    //Method to insert new item in list
    void insertElement(int, int);

    //Method to delete highest priority node
    void deleteNode();

    //Method to print list
    void displayList();

    //Method to get highest priority element
    void getElement();

    //Method to get highest priority
    void getPriority();

    //Method to check list is empty
    void checkList();
};

void priorityQueue::insertElement (int element, int priority)
{
    node *newNode = new node;
    newNode->item = element;
    newNode->priority = priority;

    if(start == nullptr)
    {
        start = newNode;
        newNode->next = nullptr;
    }
    else
    {
        node *temp = start, *prev = start;
        while(temp != nullptr && temp->priority > newNode->priority)
        {
            prev = temp;
            temp = temp->next;
        }

        if(temp == nullptr)
        {
            prev->next = newNode;
            newNode->next = nullptr;
        } 
        else if(temp->priority == newNode->priority)
        {
            prev = temp;
            temp = temp->next;
            prev->next = newNode;
            newNode->next = temp;
        }
        else if((prev->priority > newNode->priority) && (temp->priority < newNode->priority))
        {
            prev->next = newNode;
            newNode->next = temp;
        }
        else
        {
            newNode->next = start;
            start = newNode;
        }
    }
}

void priorityQueue ::deleteNode ()
{
    if(start == nullptr)
    {
        cout<<"List underflow";
        return;
    }

    node *temp = start;
    start = start->next;
    temp->next = nullptr;
    delete temp;
    temp = nullptr;
    displayList();
}

void priorityQueue ::displayList ()
{
    if(start == nullptr)
    {
        cout<<"List underflow";
        return;
    }
    node *print = start;
    while (print)
    {
        cout<<print->item <<" ";
        print = print->next;
    }
    
}

void priorityQueue::getElement()
{
    if(start == nullptr)
    {
        cout<<"List underflow";
        return;
    }

    cout<<"Highest Priority Element: "<<start->item;
}

void priorityQueue::getPriority()
{
    if(start == nullptr)
    {
        cout<<"List underflow";
        return;
    }

    cout<<"Highest Priority: "<<start->priority;
}

void priorityQueue::checkList()
{
    if(start == nullptr)
    {
        cout<<"List underflow";
        return;
    }
    cout<<"List is not empty";
}

int menu()
{
    int choice;
    cout << endl
         << endl
         << "1.Insert an element" << endl;
    cout << "2.Delete an element" << endl;
    cout << "3.Display queue" << endl;
    cout << "4.Get highest priority element" << endl;
    cout << "5.Get highest priority" << endl;
    cout << "6.Check underflow" << endl;
    cout << "7.Exit program" << endl
         << endl;

    cout << "Enter your choice: ";
    cin >> choice;

    return choice;
}

int main()
{
    priorityQueue obj;
    while (true)
    {
        switch (menu())
        {
        case 1:
            int data, pri;
            cout << "Enter element & priority number: ";
            cin >> data >>pri;
            obj.insertElement(data, pri);
            break;

        case 2:
            obj.deleteNode();
            break;

        case 3:
            obj.displayList();
            break;

        case 4:
            obj.getElement();
            break;

        case 5:
            obj.getPriority();
            break;

        case 6:
            obj.checkList();
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