#include <iostream>
using namespace std;
template <typename T>
struct node
{
    node<T> *prev;
    T item;
    node<T> *next;
};

template <typename T>
class CDLL
{
private:
    node<T> *start;

public:
    // Constructor to initialize pointer with NULL
    CDLL() : start(nullptr) {}

    //Destructor to deallocates memory for all nodes in the linked list
    ~CDLL()
    {
        while(start != nullptr)
            delete_firstNode();

        start = nullptr; //Reset pointer
    }

    //Copy constructor to implement deep copy
    CDLL(CDLL &other)
    {
        if(other.start == nullptr)
            start = nullptr;
        else
        {
            node<T> *temp = nullptr;
            while(temp != other.start)
            {
                temp = other.start;
                insertData_inEnd(temp->item);
                temp = temp->next;
            }
        }
    }

    //Copy assignment operator to implement deep copy
    CDLL& operator=(CDLL &other)
    {
        while(start != nullptr)
            delete_firstNode();

        if(other.start == nullptr)
            start = nullptr;
        else
        {
            node<T> *temp = nullptr;
            while(temp != other.start)
            {
                temp = other.start;
                insertData_inEnd(temp->item);
                temp = temp->next;
            }
        }
        return *this;
    }

    // Method to insert a data into the list at the beginning
    void insertData_inBeginning(T);

    // Method insert a data into the list at the end
    void insertData_inEnd(T);

    // Method to insert a data into the list after the specified node
    void insertData_afterNode(T, T);

    // Method to display linked list
    void displayCDLL();

    // Method to search a node with the give item
    void searchNode(T);

    // Method to delete first node from the list
    void delete_firstNode();

    // Method to delete last node from the list
    void delete_lastNode();

    // Method to delete specific node
    void delete_specificNode(T);
};

template <typename T>
void CDLL<T>::insertData_inBeginning(T data)
{
    node<T> *newNode = new node<T>;
    newNode->item = data;

    if (start == nullptr)
    {
        start = newNode;
        newNode->prev = start;
        newNode->next = start;
    }
    else
    {
        newNode->next = start;
        newNode->prev = start->prev;
        start->prev = newNode;
        start = newNode;
        start->prev->next = newNode;
    }
}

template <typename T>
void CDLL<T>::insertData_inEnd(T data)
{
    node<T> *newNode = new node<T>;
    newNode->item = data;

    if (start == nullptr)
    {
        start = newNode;
        newNode->prev = start;
        newNode->next = start;
    }
    else
    {
        newNode->prev = start->prev;
        start->prev->next = newNode;
        newNode->next = start;
        start->prev = newNode;
    }
}

template <typename T>
void CDLL<T>::insertData_afterNode(T preData, T data)
{
    if (start == nullptr)
        cout << "List is empty";
    else
    {
        node<T> *check = start;
        int flag = 0;
        while (check != start->prev)
        {
            if (check->item == preData)
            {
                flag = 1;

                // Adding new node to list
                node<T> *temp = new node<T>;
                temp->item = data;
                temp->next = check->next;
                check->next->prev = temp;
                check->next = temp;
                temp->prev = check;

                temp = nullptr;  // Avoid dangling pointer
                check = nullptr; // Avoid dangling pointer

                cout << "List(after " << data << " insertion): ";
                this->displayCDLL();
                break;
            }

            check = check->next;
        }

        if (flag == 0)
        {
            if (check->item == preData)
            {
                flag = 1;

                // Adding new node to list
                node<T> *temp = new node<T>;
                temp->item = data;
                temp->next = check->next;
                check->next->prev = temp;
                check->next = temp;
                temp->prev = check;

                temp = nullptr;  // Avoid dangling pointer
                check = nullptr; // Avoid dangling pointer

                cout << "List(after " << data << " insertion): ";
                this->displayCDLL();
            }

            if (flag == 0)
                cout << data << " not insert: " << preData << " not found in the list";

            check = nullptr; // Avoid dangling pointer
        }
    }
}

template <typename T>
void CDLL<T>::displayCDLL()
{
    if (start == nullptr)
        cout << "List is empty";
    else
    {
        node<T> *print = start;
        while (print != start->prev)
        {
            cout << print->item << " ";
            print = print->next;
        }
        cout << print->item;
        print = nullptr;
    }
}

template <typename T>
void CDLL<T>::searchNode(T data)
{
    if (start == nullptr)
        cout << "List is empty";
    else
    {
        node<T> *check = start;
        int i = 0, flag = 0;
        while (check != start->prev)
        {
            i++;
            if (check->item == data)
            {
                cout << endl
                     << data << " avilable in node " << i;
                flag = 1;
                break;
            }

            check = check->next;
        }

        if (flag == 0)
        {
            if (check->item == data)
            {
                i++;
                cout << endl
                     << data << " avilable in node " << i;
                flag = 1;
            }
        }

        if (flag == 0)
            cout << endl
                 << data << " not found";
        check = nullptr; // Avoid dangling pointer
    }
}

template <typename T>
void CDLL<T>::delete_firstNode()
{
    if(start == nullptr)
        cout<<endl <<"List is empty";
    else if(start->prev == start->prev->next)
    {
        start->prev = nullptr;
        start->next = nullptr;

        delete start;
        start = nullptr;
        cout<<"First node deleted, now list is empty";
    }
    else
    {
        node<T> *temp = start; //Allocate first node address to temp pointer

        start = start->next;
        start->prev = temp->prev;
        
        temp->prev->next = start;

        temp->prev = nullptr; //Avoid dangling pointer
        temp->next = nullptr; //Avoid dangling pointer

        delete temp; //Deallocate first node address to temp pointer
        temp = nullptr; //Avoid dangling pointer

        cout<<"List(1st node deleted): ";
        this->displayCDLL();
    }
}

template <typename T>
void CDLL<T>::delete_lastNode()
{
    if(start == nullptr)
        cout<<endl <<"List is empty";
    else if(start->prev == start->prev->next)
        delete_firstNode();
    else
    {
        node<T> *check = start;
        while(check->next != start) //Traverse until last node not found
            check = check->next;

        //Deleting last node
        check->prev->next = start;
        start->prev = check->prev;

        check->prev = nullptr;
        check->next = nullptr;
        delete check;
        check = nullptr;

        cout<<"List(last node deleted): ";
        this->displayCDLL();
    }
}

template <typename T>
void CDLL<T>::delete_specificNode(T data)
{
    if(start == nullptr)
        cout<<endl <<"List is empty";
    else if(start->prev == start->prev->next)
    {
        if(start->item = data)
            delete_firstNode();
        else
            cout<<data<<" not found in list";
    }
    else
    {
        int flag = 0;
        node<T> *check = start;
        while(check->next != start)
        {
            if(check->item == data)
            {
                flag = 1;
                check->prev->next = check->next;
                check->next->prev = check->prev;

                check->prev = nullptr;
                check->next = nullptr;
                delete check;  //Deallocate memory
                check = nullptr;  //Avoid dangling pointer
                break;
            }


            check = check->next;
        }

        if(flag == 0)
            cout<<data<<" not found in list";
        else
        {
            cout<<"List(deleted item "<<data <<"): "<<endl;
            this->displayCDLL();
        }
    }
}

int main()
{
    CDLL <string>obj;
    obj.insertData_inEnd("Amitesh");
    obj.insertData_inEnd("Amitesh");
    obj.insertData_inEnd("Rajan");
    obj.displayCDLL();

    return 0;
}