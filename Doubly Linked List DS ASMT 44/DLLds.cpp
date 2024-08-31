#include<iostream>
using namespace std;
struct node
{
    node *prev;
    int item;
    node *next;
};

class DLL
{
    private:
        node *start;
    
    public:
        //Constructor to initialize pointer with NULL
        DLL():start(nullptr){}

        //Destructor to deallocates memory for all nodes in the linked list 
        ~DLL()
        {
            while(start != nullptr)
                delete_firstNode(); //Delete first node one by one

            start = nullptr; //Reset start to avoid dangling, it's not nessecery    
        }  
    

        //Copy constructor to implement deep copy
        DLL(DLL &other)
        {
            if(other.start == nullptr)
                start = nullptr;
            else
            {
                this->start = nullptr;

                node *temp = other.start;
                while(temp != nullptr)
                {
                    this->insertData_inEnd(temp->item);
                    temp = temp->next;
                }
            }
        }

        //Copy assignment operator to implement deep copy
        DLL& operator=(DLL &other)  
        {
            while(start != nullptr)
                this->delete_firstNode();
            
            if(other.start == nullptr)
                return *this;
            else
            {
                node *temp = other.start;
                while(temp != nullptr)
                {
                    this->insertData_inEnd(temp->item);
                    temp = temp->next;
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
        void displayDLL();

        //Method to search a node with the give item
        void searchNode(int);

        //Method to delete first node from the list
        void delete_firstNode();

        //Method to delete last node from the list
        void delete_lastNode();

        //Method to delete specific node
        void delete_specificNode(int);
};

void DLL::insertData_inBeginning(int data)
{
    node *newNode = new node; //Allocate memory for new node

    //Preparing new node
    newNode->prev = nullptr;
    newNode->item = data;
    newNode->next = start;

    if(start == nullptr)
        start = newNode;
    else
    {
        start->prev = newNode;
        start = newNode;
    }
}

void DLL::insertData_inEnd(int data)
{
    node *newNode = new node; //Allocate memory for new node

    //Preparing new node
    newNode->prev = nullptr;
    newNode->item = data;
    newNode->next = nullptr;
    
    if(start == nullptr)
        start = newNode;
    else
    {
        node *check = start;
        while(check->next != nullptr)
            check = check->next;

        newNode->prev = check;
        check->next = newNode;
    }
}

void DLL::insertData_afterNode(int preData, int data)
{
    if(start == nullptr)
        cout<<"List is empty";
    else
    {
        int i=0, flag = 0;
        node *check = start;
        while(check != nullptr)
        {
            i++;
            if(check->item == preData)
            {
                flag = 1;
                node *newNode = new node; //Allocate memory for new data node

                //Preparing node
                newNode->item = data;
                newNode->next = check->next;
                newNode->prev = check;
                check->next = newNode;

                check = nullptr;
                cout<<"List(after "<<data <<" insertion): ";
                this->displayDLL();
                break;
            }
            check = check->next;
        }
        if(flag == 0)
            cout<<data <<" not insert: "<<preData <<" not found in the list";
    }
     
}

void DLL::displayDLL()
{
    if(start == nullptr)
        cout<<"List is empty";
    else
    {
        node *check = start;
        while(check != nullptr)
        {
            cout<<check->item <<" ";
            check = check->next;
        }
    }   
}

void DLL::searchNode(int data)
{
    if(start == nullptr)
        cout<<"List is empty";
    else
    {
        node *check = start;
        int i=0,flag=0;
        while(check != nullptr)
        {
            i++;
            if(check->item == data)
            {
                cout<<endl <<data <<" avilable in node "<<i;
                flag = 1;
                check = nullptr;
                break;
            }

            check = check->next;
        }
        if(flag == 0)
            cout<<data <<" not found";
    }
}

void DLL::delete_firstNode()
{
    if(start == nullptr)
        cout<<"List is empty";
    else if(start->next == nullptr)
    {
        start->next = nullptr;
        delete start;
        start = nullptr;

        cout<<"First node deleted, now list is empty";
    }
    else
    {
        node *temp = start;
        start = start->next;
        start->prev = nullptr;
        temp->next = nullptr;

        delete temp;
        temp = nullptr;

        cout<<"List(1st node deleted): ";
        this->displayDLL();
    }  
}

void DLL::delete_lastNode()
{
    if(start == nullptr)
        cout<<"List is empty";
    else if(start->next == nullptr)
        delete_firstNode();
    else
    {
        node *temp = start, *check = nullptr;
        while(temp->next != nullptr)
        {
            check = temp;
            temp = temp->next;
        }

        check->next = nullptr;

        delete temp;
        temp = nullptr;

        cout<<"List(last node deleted): ";
        this->displayDLL();
    }
}

void DLL::delete_specificNode(int data)
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
        node *pre = nullptr, *check = start, *forwd = nullptr;
        while(check->next != nullptr)
        {
            if(check->item == data)
            {
                flag = 1;
                forwd = check->next;
                pre->next = forwd;
                forwd->prev = pre;

                cout<<"List(deleted item "<<data <<"): "<<endl;
                this->displayDLL();

                //Avoid dangling pointer
                check->prev = nullptr;
                check->next = nullptr;
                delete check;
                check = nullptr;
                pre = nullptr;
                forwd =nullptr;
                break;   
            }
            
            pre = check;
            check = check->next;
        }

        if(flag == 0)
            cout<<data<<" not found in list";

        //Avoid dangling pointer
        delete check;
        check = nullptr;
        pre = nullptr;
        forwd = nullptr;
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
    DLL obj;

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
            obj.displayDLL();
            break;

        case 9:
            cout << "Program has been ended!";
            exit(0);

        default:
            cout << "Invalid Choice";
            break;
        }
    }

    DLL OBJ = obj;
    OBJ.displayDLL();

    return 0;
}