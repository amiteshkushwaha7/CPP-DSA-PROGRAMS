#include<iostream>
using namespace std;
struct node
{
    int item;
    node *next;
};

class CLL
{
    private:
        node *last;
    
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
                node *temp = nullptr;
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
                node *temp = nullptr;
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
        void insertData_inBeginning(int);

        //Method insert a data into the list at the end
        void insertData_inEnd(int);

        //Method to insert a data into the list after the specified node
        void insertData_afterNode(int, int);

        //Method to display linked list
        void displayCLL();

        //Method to search a node with the give item
        void searchNode(int);

        //Method to delete first node from the list
        void delete_firstNode();

        //Method to delete last node from the list
        void delete_lastNode();

        //Method to delete specific node
        void delete_specificNode(int);
};

void CLL::insertData_inBeginning(int data)
{
    node *newNode = new node;
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

void CLL::insertData_inEnd(int data)
{
    node *newNode = new node;
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

void CLL::insertData_afterNode(int preData, int data)
{
    if(last == nullptr)
        cout<<"List is empty";
    else
    {
        node *check = last->next;
        int flag = 0;
        while(check != last)
        {
            if(check->item == preData)
            {
                flag = 1;
                node *temp = new node;
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

void CLL::displayCLL()
{
    if(last == nullptr)
        cout<<"List is empty";
    else
    {
        node *print = last->next;
        while(print != last)
        {
            cout<<print->item <<" ";
            print = print->next;
        }
        cout<<print->item;
        print = nullptr;
    }
}

void CLL::searchNode(int data)
{
    if(last == nullptr)
        cout<<"List is empty";
    else
    {
        node *check = last->next;
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

void CLL::delete_firstNode()
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
        node *temp = last->next; //Allocate first node address to temp pointer

        last->next = temp->next;
        temp->next = nullptr; //Avoid dangling pointer

        delete temp; //Deallocate first node address to temp pointer
        temp = nullptr; //Avoid dangling pointer

        cout<<"List(1st node deleted): ";
        this->displayCLL();
    }  
}

void CLL::delete_lastNode()
{
    if(last == nullptr)
        cout<<endl <<"List is empty";
    else if(last == last->next)
        delete_firstNode();
    else
    {
        node *check = last->next;
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

void CLL::delete_specificNode(int data)
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
        node *pre = nullptr, *check = last->next;
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
    CLL obj;

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
            obj.displayCLL();
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