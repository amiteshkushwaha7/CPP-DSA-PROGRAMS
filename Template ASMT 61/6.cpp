#include<iostream>
using namespace std;
template <typename T>
struct node
{
    node *prev;
    T item;
    node *next;
};

template <typename T>
class SLL
{
    private:
        node<T> *start;
    
    public:
        //Constructor to initialize start pointer with NULL
        SLL():start(nullptr){}

        //Destructor to deallocates memory for all nodes in the linked list 
        ~SLL()
        {
            while(start != nullptr)
                delete_firstNode(); //Delete first node one by one

            start = nullptr; //Reset start to avoid dangling, it's not nessecery
        }  
    

        //Copy constructor to implement deep copy
        SLL(SLL &other)
        {
            if(other.start == nullptr)
                start = nullptr;
            else
            {
                this->start = nullptr;

                node<T> *currentSrc = other.start;
                while(currentSrc != nullptr)
                {
                    this->insertData_inEnd(currentSrc->item);
                    currentSrc = currentSrc->next;
                }
            }
        }

        //Copy assignment operator to implement deep copy
        SLL& operator=(SLL &other)  
        {
            while(start != nullptr)
                this->delete_firstNode();

            if(other.start == nullptr)
                return *this;
            else
            {
                node<T> *currentSrc = other.start;
                while(currentSrc != nullptr)
                {
                    this->insertData_inEnd(currentSrc->item);
                    currentSrc = currentSrc->next;
                }
                return *this;
            }
        }

        //Method to insert a data into the list at the beginning
        void insertData_inBeginning(T);

        //Method insert a data into the list at the end
        void insertData_inEnd(T);

        //Method to insert a data into the list after the specified node
        void insertData_afterNode(T, T);

        //Method to display linked list
        void displaySLL();

        //Method to search a node with the give item
        void searchNode(T);

        //Method to delete first node from the list
        void delete_firstNode();

        //Method to delete last node from the list
        void delete_lastNode();

        //Method to delete specific node
        void delete_specificNode(T);
};

template <typename T>
void SLL<T>::insertData_inBeginning(T data)
{
    node<T>* newNode = new node<T>; //Allocate memory for new node and assign it's address to new node pointer newNode
    newNode->item = data; //Assign data to first node's item
    newNode->next = start; //Assign next pointer to previous node

    start = newNode; //Assign start pointer to leatest node
}

template <typename T>
void SLL<T>::insertData_inEnd(T data)
{
    node<T> *newNode = new node<T>; //Allocate memory for new node and assign it's address to new node pointer newNode
    newNode->item = data; //Assign data to latest node's item
    newNode->next = nullptr;  
    

    if(start == nullptr)
        start = newNode;    
    else
    {
        node<T> *current = start; //Pointer to traverse current list
        while(current->next != nullptr)
            current = current->next;  

        current->next = newNode; //Assign latest node to the end of list
        current = nullptr; //Reset pointer
    }
}

template <typename T>
void SLL<T>::insertData_afterNode(T preData, T data)
{
    if(start == nullptr)
        cout<<"List is empty";
    else
    {
        int flag = 0;
        node<T> *check = start;
        while(check->next != nullptr)
        {
            if(check->item == preData)
            {
                flag = 1;
                node<T> *temp = check->next;

                node<T> *newNode = new node<T>;
                newNode->item = data;
                newNode->next = temp;

                check->next = newNode;

                cout<<"List(after "<<data <<" insertion): ";
                this->displaySLL();
                break;
            }
            check = check->next;
        }
        if(flag == 0)
            cout<<data <<" not insert: "<<preData <<" not found in the list";
    }
}

template <typename T>
void SLL<T>::displaySLL()
{
    node<T> *print;
    print = start;

    if(start == nullptr)
        cout<<"List is empty";
    else
    {
        while(print != nullptr)
        {
            cout<<print->item <<" ";
            print = print->next;
        }
    }
    print = nullptr; //Avoid dangling pointer
}

template <typename T>
void SLL<T>::searchNode(T data)
{
    node<T> *check;
    check = start;
    if(start == nullptr)
        cout<<endl <<"List is empty";
    else
    {
        int i=0,flag=0;
        while(check != nullptr)
        {
            i++;
            if(check->item == data)
            {
                cout<<endl <<data <<" avilable in node "<<i;
                flag = 1;
                break;
            }

            check = check->next;
        }
        if(flag == 0)
            cout<<endl <<data <<" not found";
    }
    delete check;  //Deallocate memory
    check = nullptr; //Avoid dangling pointer
}

template <typename T>
void SLL<T>::delete_firstNode()
{
    if(start == nullptr)
        cout<<endl <<"List is empty";
    else
    {
        node<T> *temp = start; //Allocate first node address to temp pointer

        start = start->next; //Allocate second node address to start pointer
        temp->next = nullptr; //Avoid dangling pointer

        delete temp; //Deallocate first node address to temp pointer
        temp = nullptr; //Avoid dangling pointer

        cout<<"List(1st node deleted): ";
        this->displaySLL();
    }
    
}

template <typename T>
void SLL<T>::delete_lastNode()
{
    if(start == nullptr)
        cout<<endl <<"List is empty";
    else if(start->next == nullptr)
        delete_firstNode();
    else
    {
        node<T> *temp = nullptr, *check = start;
        while(check->next != nullptr)
        {
            temp = check;
            check = check->next;
        }

        temp->next = nullptr; //Avoid dangling pointer

        delete check; //Deallocated memory
        check = nullptr; //Avoid dangling pointer

        temp = nullptr; //Avoid dangling pointer
        cout<<"List(last node deleted): ";
        displaySLL();
    }
}

template <typename T>
void SLL<T>::delete_specificNode(T data)
{
    if(start == nullptr)
        cout<<endl <<"List is empty";
    else if(start->next == nullptr)
    {
        if(start->item == data)
            delete_firstNode();
        else
            cout<<data<<" not found in list";
    }
    else
    {
        int flag = 0;
        node<T> *pre = nullptr, *check = start;
        while(check->next != nullptr)
        {
            if(check->item == data)
            {
                flag = 1;
                pre->next = check->next; //Connect previous and forword node of deleted node
        
                check->next = nullptr;  //Avoid dangling pointer
                delete check;  //Deallocate memory
                check = nullptr;  //Avoid dangling pointer
        
                pre = nullptr;  //Avoid dangling pointer
                break;
            }
            
            pre = check;
            check = check->next;
        }

        if(flag == 0)
            cout<<data<<" not found in list";
        else
        {
            cout<<"List(deleted item "<<data <<"): "<<endl;
            this->displaySLL();
        }
    }
}

int main()
{
    SLL <string>obj;
    obj.insertData_inEnd("Amitesh");
    obj.insertData_inEnd("Rajan");
    obj.insertData_inEnd("Ankur");
    obj.displaySLL();

    return 0;
}