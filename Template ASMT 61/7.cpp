#include<iostream>
using namespace std;
template <typename T>
struct node
{
    T item;
    node<T> *next;
};

template <typename T>
class CLL
{
    private:
        node<T> *last;
    
    public:
        //Constructor to initialize pointer with NULL
        CLL():last(nullptr){}

        //Destructor to deallocates memory for all nodes in the linked list 
        ~CLL()
        {
            while(last != nullptr)
                delete_firstNode();

            last = nullptr; //Reset pointer
        }  
    

        //Copy constructor to implement deep copy
        CLL(CLL &other)
        {
            if(other.last == nullptr)
                last = nullptr;
            else
            {
                node<T> *temp = nullptr;
                while(temp != other.last->next)
                {
                    temp = other.last->next;
                    insertData_inEnd(temp->item);
                    temp = temp->next;
                }
            }
        }

        //Copy assignment operator to implement deep copy
        CLL& operator=(CLL &other)  
        {
            while(last != nullptr)
                delete_firstNode();
            
            if(other.last == nullptr)
                last = nullptr;
            else
            {
                node<T> *temp = nullptr;
                while(temp != other.last->next)
                {
                    temp = other.last->next;
                    insertData_inEnd(temp->item);
                    temp = temp->next;
                }
            }
            return *this;
        }

        //Method to insert a data into the list at the beginning
        void insertData_inBeginning(T);

        //Method insert a data into the list at the end
        void insertData_inEnd(T);

        //Method to insert a data into the list after the specified node
        void insertData_afterNode(T, T);

        //Method to display linked list
        void displayCLL();

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
void CLL<T>::insertData_inBeginning(T data)
{
    node<T> *newNode = new node<T>;
    newNode->item = data;

    if(last == nullptr)
    {
        last = newNode;
        newNode->next = last;
    }
    else
    {
        newNode->next = last->next;
        last->next = newNode;
    }
}

template <typename T>
void CLL<T>::insertData_inEnd(T data)
{
    node<T> *newNode = new node<T>;
    newNode->item = data;

    if(last == nullptr)
    {
        last = newNode;
        newNode->next = last;
    }
    else
    {
        newNode->next = last->next;
        last->next = newNode;
        last = newNode;
    }
}

template <typename T>
void CLL<T>::insertData_afterNode(T preData, T data)
{
    if(last == nullptr)
        cout<<"List is empty";
    else
    {
        node<T> *check = last->next;
        int flag = 0;
        while(check != last)
        {
            if(check->item == preData)
            {
                flag = 1;
                node<T> *temp = new node<T>;
                temp->item = data;
                temp->next = check->next;
                check->next = temp;

                temp = nullptr; //Avoid dangling pointer
                check = nullptr;  //Avoid dangling pointer

                cout<<"List(after "<<data <<" insertion): ";
                this->displayCLL();
                break;
            }

            check = check->next;
        }
        
        if(flag == 0)
            cout<<data <<" not insert: "<<preData <<" not found in the list";  

        check = nullptr;  //Avoid dangling pointer    
    }
}

template <typename T>
void CLL<T>::displayCLL()
{
    if(last == nullptr)
        cout<<"List is empty";
    else
    {
        node<T> *print = last->next;
        while(print != last)
        {
            cout<<print->item <<" ";
            print = print->next;
        }
        cout<<print->item;
        print = nullptr;
    }
}

template <typename T>
void CLL<T>::searchNode(T data)
{
    if(last == nullptr)
        cout<<"List is empty";
    else
    {
        node<T> *check = last->next;
        int i=0,flag=0;
        while(check != last)
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
        check = nullptr; //Avoid dangling pointer
    }
}

template <typename T>
void CLL<T>::delete_firstNode()
{
    if(last == nullptr)
        cout<<endl <<"List is empty";
    else if(last == last->next)
    {
        last->next = nullptr;
        delete last;
        last = nullptr;

        cout<<"First node deleted, now list is empty";
    }
    else
    {
        node<T> *temp = last->next; //Allocate first node address to temp pointer

        last->next = temp->next;
        temp->next = nullptr; //Avoid dangling pointer

        delete temp; //Deallocate first node address to temp pointer
        temp = nullptr; //Avoid dangling pointer

        cout<<"List(1st node deleted): ";
        this->displayCLL();
    }  
}

template <typename T>
void CLL<T>::delete_lastNode()
{
    if(last == nullptr)
        cout<<endl <<"List is empty";
    else if(last == last->next)
        delete_firstNode();
    else
    {
        node<T> *check = last->next;
        while(check->next != last) //Traverse until last node not found
            check = check->next;

        //Deleting last node
        check->next = last->next; 
        last->next = nullptr; //Avoid dangling pointer
        delete last;
        last = check;

        check = nullptr; //Avoid dangling pointer
        cout<<"List(last node deleted): ";
        this->displayCLL();
    }
}

template <typename T>
void CLL<T>::delete_specificNode(T data)
{    
    if(last == nullptr)
        cout<<endl <<"List is empty";
    else if(last == last->next)
    {
        if(last->item == data)
            delete_firstNode();
        else
            cout<<data<<" not found in list";
    }
    else
    {
        int flag = 0;
        node<T> *pre = nullptr, *check = last->next;
        while(check->next != last)
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
            this->displayCLL();
        }
    }
} 

int main()
{
    CLL <string>obj;
    obj.insertData_inEnd("Amitesh");
    obj.insertData_inEnd("Amitesh");
    obj.insertData_inEnd("Rajan");
    obj.displayCLL();

    return 0;
}