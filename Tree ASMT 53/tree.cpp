#include<iostream>
using namespace std;
struct node
{
    node *left;
    int item;
    node *right;
};

class Tree
{
    private:
        node *root;
    public:
        //Constructor
        Tree():root(nullptr){}

        //Distructor
        ~Tree()
        {
            recDistructor(root);
            root = nullptr;
        }
         
        //Method to help distructor to deallocate memory of all nodes
        void recDistructor(node*);

        //Copy constructor to implement deep copy
        Tree(Tree &other)
        {
            if(other.root == nullptr)
                root = nullptr;
            else
            {
                root = new node;
                recCopy(*this, other.root);
            }
        }

        //Copy assignment operator to implement deep copy
        Tree& operator=(Tree &other)
        {
            //this->root= new node;
            root = nullptr; 
            other.recCopy(*this, other.root);
           return *this;
        }

        //Method to help copy assignment operator to copy element
        void recCopy(Tree&, node*);

        //Method to insert data in tree
        void insertElement(int);

        //Method for preorder traversing
        void preTraverse(node*);

        //Method for postorder traversing
        void postTraverse(node*);

        //Method for inorder traversing
        void inorderTraversing(node*);

        //Method to delete an element
        void deleteElement(int);

        //Method to search an element
        void searchElement(int);

        //Method to check null tree
        void checkTree();

        //Method to get root
        node* getRoot();
};

void Tree::recCopy(Tree &tempRoot, node *temp)
{
    if(temp != nullptr)
    {
        cout << temp -> item <<" ";

        tempRoot.insertElement(temp->item);
        recCopy(tempRoot, temp->left);
        recCopy(tempRoot, temp->right);
    }
}

void Tree::recDistructor(node *temp)
{
    if(temp != nullptr)
    {
        recDistructor(temp->left);
        recDistructor(temp->right);

        delete temp;
        //temp = nullptr;
    }
}

void Tree::insertElement(int element)
{
    node *newNode = new node;
    newNode->left = nullptr;
    newNode->item = element;
    newNode->right = nullptr;

    if(root == nullptr)
        root = newNode;
    else
    {
        node *temp = root, *prev = nullptr;
        while(temp != nullptr)
        {
            if(element == temp->item)
            {
                cout<<"Can't insert duplicate value: "<<element;
                delete newNode;
                newNode = nullptr;
                return;
            }
            if(temp->item > newNode->item)
            {
                prev = temp;
                temp = temp->left;
            }
            else
            {
                prev = temp;
                temp = temp->right;
            }
        }
    
        if(prev->item > newNode->item)
            prev->left = newNode;
        else
            prev->right = newNode; 
    }
}

void Tree::inorderTraversing(node *temp)
{
    if(temp != nullptr)
    {
        inorderTraversing(temp->left);
        cout<<temp->item <<" ";

        inorderTraversing(temp->right);
    }
}

void Tree::preTraverse(node *temp)
{
    if(temp != nullptr)
    {
        cout<<temp->item <<" ";
        preTraverse(temp->left);
        preTraverse(temp->right);
    }
}

void Tree::postTraverse(node *temp)
{
    if(temp != nullptr)
    {
        postTraverse(temp->left);
        postTraverse(temp->right);
        cout<<temp->item <<" ";
    }
}

void Tree::searchElement(int element)
{
    if(root == nullptr)
    {
        cout<<"Tree is empty";
        return;
    }

    node *temp = root;
    int flag = 0;
    while(temp != nullptr)
    {
        if(element == temp->item)
        {
            flag = 1;
            cout<<"Element found";
            return;
        }

        if(element < temp->item)
            temp = temp->left;
        else 
            temp = temp->right;
    }

    if(flag == 0)
        cout<<"Element not found";
}

void Tree::deleteElement(int element)
{
    if(root == nullptr)
    {
        cout<<"Tree is empty";
        return;
    }
    
    node *temp = root, *prev = nullptr;
    while(temp != nullptr)
    {
        if(element == temp->item)
        {
            if(temp->left == nullptr && temp->right == nullptr)
            {
                if(prev->left->item == element)
                    prev->left = nullptr;
                else
                    prev->right = nullptr;
                
                cout<<"Element deleted";
                return;
            }
            else if(temp->left != nullptr && temp->right != nullptr)
            {
                node *min = temp->right;
                while (min->left != nullptr)
                {
                    prev = min;
                    min = min->left;
                }
                
                temp->item = min->item;
                if(min->right != nullptr)
                {
                    min = min->right;
                    prev->left->right = nullptr;
                    prev->left = nullptr;
                    min->right = nullptr;
                    if(prev->left->item > min->item)
                        prev->left->left = min;
                    else
                        prev->left->right = min;
                }
                else 
                    prev->left = nullptr;
                cout<<"Element deleted";
                return;
            }
            else
            { 
                if(temp->right != nullptr)
                {
                    node *check = temp->right;
                    temp->right = nullptr;

                    if(check->item < prev->item)
                        prev->left = check;
                    else 
                        prev->right = check;

                    delete temp;
                    temp = nullptr;
                    cout<<"Element deleted";
                    return;

                }
                else
                {
                    node *check = temp->left;
                    temp->left = nullptr;

                    if(check->item < prev->item)
                        prev->left = check;
                    else 
                        prev->right = check;

                    delete temp;
                    temp = nullptr;
                    cout<<"Element deleted";
                    return;
                }
            }
        }
        else if(element < temp->item)
        {
            prev = temp;
            temp = temp->left;
        }
        else
        {
            prev = temp;
            temp = temp->right;
        }
    }
    cout<<"Element not found";
}

void Tree::checkTree()
{
    if(root == nullptr)
    {
        cout<<"Tree is null";
        return;
    }
    cout<<"Tree is not null";
}

node* Tree::getRoot()
{
    return root;
}

int menu()
{
    int choice;
    cout << endl
         << endl
         << "1.Insert an element" << endl;
    cout << "2.Inorder traversing" << endl;
    cout << "3.Preorder traversing" << endl;
    cout << "4.Postorder traversing" << endl;
    cout << "5.Delete an element" << endl;
    cout << "6.Check tree is empty or not" << endl;
    cout << "7.Search an element" << endl;
    cout << "8.Exit program" << endl
         << endl;

    cout << "Enter your choice: ";
    cin >> choice;

    return choice;
}

int main()
{
    Tree obj;
    // while (true)
    // {
    //     switch (menu())
    //     {
    //     case 1:
    //         int data;
    //         cout << "Enter element: ";
    //         cin >> data;
    //         obj.insertElement(data);
    //         break;

    //     case 2:
    //         if(obj.getRoot() == nullptr)
    //             cout<<"Tree is empty";
    //         else
    //             obj.inorderTraversing(obj.getRoot());
    //         break;

    //     case 3:
    //         if(obj.getRoot() == nullptr)
    //             cout<<"Tree is empty";
    //         else
    //             obj.preTraverse(obj.getRoot());
    //         break;

    //     case 4:
    //         if(obj.getRoot() == nullptr)
    //             cout<<"Tree is empty";
    //         else
    //             obj.postTraverse(obj.getRoot());
    //         break;

    //     case 5:
    //         int Data;
    //         cout << "Enter element: ";
    //         cin >> Data;
    //         obj.deleteElement(Data);
    //         break;

    //     case 6:
    //         obj.checkTree();
    //         break;

    //     case 7:
    //         int d;
    //         cout << "Enter element: ";
    //         cin >> d;
    //         obj.searchElement(d);
    //         break;

    //     case 8:
    //         cout << "Program has been ended!";
    //         exit(0);

    //     default:
    //         cout << "Invalid Choice";
    //         break;
    //     }
    // }
    obj.insertElement(10);
    obj.insertElement(5);
    obj.insertElement(15);
    obj.insertElement(3);
    obj.insertElement(7);
    obj.insertElement(11);
    obj.insertElement(20);
    obj.inorderTraversing(obj.getRoot());
    cout<<endl;

    Tree obj2;
    obj2=obj;
    obj2.inorderTraversing(obj2.getRoot());

    return 0;
    
}