#include<iostream>
using namespace std;
struct node
{
    node *prev;
    int item;
    node *next;
};

class SLL
{
    private:
        node *start;
    
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

                node *currentSrc = other.start;
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
                node *currentSrc = other.start;
                while(currentSrc != nullptr)
                {
                    this->insertData_inEnd(currentSrc->item);
                    currentSrc = currentSrc->next;
                }
                return *this;
            }
        }

        //Method to insert a data into the list at the beginning
        void insertData_inBeginning(int);

        //Method insert a data into the list at the end
        void insertData_inEnd(int);

        //Method to insert a data into the list after the specified node
        void insertData_afterNode(int, int);

        //Method to display linked list
        void displaySLL();

        //Method to search a node with the give item
        void searchNode(int);

        //Method to delete first node from the list
        void delete_firstNode();

        //Method to delete last node from the list
        void delete_lastNode();

        //Method to delete specific node
        void delete_specificNode(int);
};

void SLL::insertData_inBeginning(int data)
{
    node *newNode = new node; //Allocate memory for new node and assign it's address to new node pointer newNode
    newNode->item = data; //Assign data to first node's item
    newNode->next = start; //Assign next pointer to previous node

    start = newNode; //Assign start pointer to leatest node
}

void SLL::insertData_inEnd(int data)
{
    node *newNode = new node; //Allocate memory for new node and assign it's address to new node pointer newNode
    newNode->item = data; //Assign data to latest node's item
    newNode->next = nullptr;  
    

    if(start == nullptr)
        start = newNode;    
    else
    {
        node *current = start; //Pointer to traverse current list
        while(current->next != nullptr)
            current = current->next;  

        current->next = newNode; //Assign latest node to the end of list
        current = nullptr; //Reset pointer
    }
}

void SLL::insertData_afterNode(int preData, int data)
{
    if(start == nullptr)
        cout<<"List is empty";
    else
    {
        int flag = 0;
        node *check = start;
        while(check->next != nullptr)
        {
            if(check->item == preData)
            {
                flag = 1;
                node *temp = check->next;

                node *newNode = new node;
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

void SLL::displaySLL()
{
    node *print;
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

void SLL::searchNode(int data)
{
    node *check;
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

void SLL::delete_firstNode()
{
    if(start == nullptr)
        cout<<endl <<"List is empty";
    else
    {
        node *temp = start; //Allocate first node address to temp pointer

        start = start->next; //Allocate second node address to start pointer
        temp->next = nullptr; //Avoid dangling pointer

        delete temp; //Deallocate first node address to temp pointer
        temp = nullptr; //Avoid dangling pointer

        cout<<"List(1st node deleted): ";
        this->displaySLL();
    }
    
}

void SLL::delete_lastNode()
{
    if(start == nullptr)
        cout<<endl <<"List is empty";
    else if(start->next == nullptr)
        delete_firstNode();
    else
    {
        node *temp = nullptr, *check = start;
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

void SLL::delete_specificNode(int data)
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
        node *pre = nullptr, *check = start;
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

int menu()
{
    int choice;
    cout << endl<< endl<< "1.Insert a data into the list at the beginning" << endl;
    cout << "2.Insert a data into the list at the end" << endl;
    cout << "3.Insert a data into the list after the specified node of the list" << endl;
    cout << "4.Search a node with the give data" << endl;
    cout << "5.Delete first node from the list" << endl;
    cout << "6.Delete last node from the list" << endl;
    cout << "7.Delete a specific node from the list" << endl;
    cout << "8.Display list" << endl;
    cout << "9.Exit program" << endl << endl;

    cout << "Enter your choice: ";
    cin >> choice;

    return choice;
}

int main()
{
    SLL obj;
    while (true)
    {
        switch (menu())
        {
        case 1:
            int data;
            cout<<"Enter a data: ";
            cin>>data;
            obj.insertData_inBeginning(data);
            break;

        case 2:
            int DATA;
            cout<<"Enter a data: ";
            cin>>DATA;
            obj.insertData_inEnd(DATA);
            break;

        case 3:
            int listData,d;
            cout<<"Enter that list data, after you want to insert new data: ";
            cin>>listData;
            cout<<"Enter new data: ";
            cin>>d;
            obj.insertData_afterNode(listData, d);
            break;

        case 4:
            int D;
            cout<<"Enter a data: ";
            cin>>D;
            obj.searchNode(D);
            break;

        case 5:
            obj.delete_firstNode();
            break;

        case 6:
            obj.delete_lastNode();
            break;

        case 7:
            int item;
            cout<<"Enter the data: ";
            cin>>item;
            obj.delete_specificNode(item);
            break;

        case 8:
            obj.displaySLL();
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