#include <iostream>
using namespace std;
struct node
{
    node *prev;
    int item;
    node *next;
};

class CDLL
{
private:
    node *start;

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
            node *temp = nullptr;
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
            node *temp = nullptr;
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
    void insertData_inBeginning(int);

    // Method insert a data into the list at the end
    void insertData_inEnd(int);

    // Method to insert a data into the list after the specified node
    void insertData_afterNode(int, int);

    // Method to display linked list
    void displayCDLL();

    // Method to search a node with the give item
    void searchNode(int);

    // Method to delete first node from the list
    void delete_firstNode();

    // Method to delete last node from the list
    void delete_lastNode();

    // Method to delete specific node
    void delete_specificNode(int);
};

void CDLL::insertData_inBeginning(int data)
{
    node *newNode = new node;
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

void CDLL::insertData_inEnd(int data)
{
    node *newNode = new node;
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

void CDLL::insertData_afterNode(int preData, int data)
{
    if (start == nullptr)
        cout << "List is empty";
    else
    {
        node *check = start;
        int flag = 0;
        while (check != start->prev)
        {
            if (check->item == preData)
            {
                flag = 1;

                // Adding new node to list
                node *temp = new node;
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
                node *temp = new node;
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

void CDLL::displayCDLL()
{
    if (start == nullptr)
        cout << "List is empty";
    else
    {
        node *print = start;
        while (print != start->prev)
        {
            cout << print->item << " ";
            print = print->next;
        }
        cout << print->item;
        print = nullptr;
    }
}

void CDLL::searchNode(int data)
{
    if (start == nullptr)
        cout << "List is empty";
    else
    {
        node *check = start;
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

void CDLL::delete_firstNode()
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
        node *temp = start; //Allocate first node address to temp pointer

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

void CDLL::delete_lastNode()
{
    if(start == nullptr)
        cout<<endl <<"List is empty";
    else if(start->prev == start->prev->next)
        delete_firstNode();
    else
    {
        node *check = start;
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

void CDLL::delete_specificNode(int data)
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
        node *check = start;
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

int menu()
{
    int choice;
    cout << endl << endl << "1.Insert a data into the list at the beginning" << endl;
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
    CDLL obj;

    while (true)
    {
        switch (menu())
        {
        case 1:
            int data;
            cout << "Enter a data: ";
            cin >> data;
            obj.insertData_inBeginning(data);
            break;

        case 2:
            int DATA;
            cout << "Enter a data: ";
            cin >> DATA;
            obj.insertData_inEnd(DATA);
            break;

        case 3:
            int listData, d;
            cout << "Enter that list data, after you want to insert new data: ";
            cin >> listData;
            cout << "Enter new data: ";
            cin >> d;
            obj.insertData_afterNode(listData, d);
            break;

        case 4:
            int D;
            cout << "Enter a data: ";
            cin >> D;
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
            obj.displayCDLL();
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