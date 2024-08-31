#include <iostream>
#include <cstdlib>
using namespace std;
struct node
{
    node *left;
    int item;
    int height;
    int balanceFactor;
    node *right;
};

struct stackNode
{
    stackNode *prev;
    node *ptr;
    stackNode *next;
};

class STACK
{
private:
    stackNode *start;

public:
    STACK() : start(nullptr) {}

    void insertSTACK(node *temp)
    {
        stackNode *newNode = new stackNode;
        newNode->prev = nullptr;
        newNode->ptr = temp;
        newNode->next = nullptr;

        if (start == nullptr)
            start = newNode;
        else
        {
            start->prev = newNode;
            newNode->next = start;
            start = newNode;
        }
    }

    stackNode *getStart()
    {
        return start;
    }

    node *getNode()
    {
        return start->ptr;
    }

    void deleteSTACK()
    {
        if (start->next == nullptr)
        {
            delete start;
            start = nullptr;
            return;
        }

        stackNode *temp = start;
        start = start->next;
        start->prev = nullptr;

        temp->next = nullptr;
        temp->ptr = nullptr;
        delete temp;
    }

    void displaySTACK()
    {
        stackNode *temp = start;
        while (temp)
        {
            cout << temp->ptr->item << " ";
            temp = temp->next;
        }
    }

    ~STACK()
    {
        while (start)
            deleteSTACK();
    }
};

class AVL
{
private:
    node *root;
    void recInorder(node *);
    void recPreorder(node *);
    void recPostorder(node *);

public:
    // Constructor
    AVL() : root(nullptr) {}

    // Distructor
    // ~AVL()
    // {
    // }

    // Copy constructor to implement deep copy
    // AVL(AVL &other)
    // {
    // }

    // Copy assignment operator to implement deep copy
    // AVL &operator=(AVL &other)
    // {
    // }

    // Method to insert data in tree
    void insertElement(int);

    // Method to rewirte hight & balance factor of inserted node's parents
    void update(STACK &);

    // Method to rotated tree to reach avl status
    void rotation(STACK &, int);

    // Method for preorder traversing
    void preTraversing()
    {
        recPreorder(root);
    }

    // Method for postorder traversing
    void postTraversing()
    {
        recPostorder(root);
    }

    // Method for inorder traversing
    void inorderTraversing()
    {
        recInorder(root);
    }

    // Method to delete an element
    void deleteElement(int);

    // Method to search an element
    void searchElement(int);

    // Method to check null tree
    void checkTree();
};

void AVL::rotation(STACK &S, int element)
{
    stackNode *temp = S.getStart();

    while (temp)
    {
        node *scr = temp->ptr;

        if (scr->balanceFactor > 1 && (element > scr->item && element > scr->right->item))
        {
                node *A = scr;
                node *B = A->right;
                node *LT = B->left;

                B->left = A;
                A->right = LT;
                temp->next->ptr->right = A;
                
                STACK obj;
                obj.insertSTACK(temp->next->ptr);
                obj.insertSTACK(B);
                obj.insertSTACK(A);
                update(obj);
                break;
        }

        if (scr->balanceFactor > 1 && (element < scr->item && element < scr->right->item))
        {

            node *A = scr;
            node *B = A->left;
            node *RT = B->right;

            B->right = A;
            A->left = RT;
            temp->next->ptr->left = A;
            
            STACK obj;
            obj.insertSTACK(temp->next->ptr);
            obj.insertSTACK(B);
            obj.insertSTACK(A);
            update(obj);
            break;
        }
        temp = temp->next;
    }
}

void AVL::update(STACK &S)
{
    node *sour = S.getNode();

    while (sour)
    {
        int leftHeight = (sour->left) ? sour->left->height : 0;
        int rightHeight = (sour->right) ? sour->right->height : 0;

        sour->height = max(leftHeight, rightHeight) + 1;
        sour->balanceFactor = abs(leftHeight - rightHeight);

        S.deleteSTACK();
        sour = S.getStart() ? S.getNode() : nullptr;
    }
}

void AVL::insertElement(int element)
{
    STACK stack;
    STACK obj;

    if (root == nullptr)
    {
        node *newNode = new node;
        newNode->left = nullptr;
        newNode->item = element;
        newNode->height = 1;
        newNode->balanceFactor = 0;
        newNode->right = nullptr;
        root = newNode;
    }
    else
    {
        node *newNode = new node;
        newNode->left = nullptr;
        newNode->item = element;
        newNode->height = 1;
        newNode->balanceFactor = 0;
        newNode->right = nullptr;

        node *temp = root;
        while (temp)
        {
            stack.insertSTACK(temp);
            obj.insertSTACK(temp);

            if (temp->item == element)
            {
                cout << "Duplicate element can't insert: " << element;
                delete newNode;
                newNode = nullptr;
                stack.~STACK();
                return;
            }

            if (element < temp->item)
            {
                if (temp->left == nullptr)
                {
                    temp->left = newNode;
                    update(stack);
                    // rotation(obj, element);
                    break;
                }
                else
                    temp = temp->left;
            }
            else
            {
                if (temp->right == nullptr)
                {
                    temp->right = newNode;
                    update(stack);
                    // rotation(obj, element);
                    break;
                }
                else
                    temp = temp->right;
            }
        }
    }
}

void AVL::recInorder(node *temp)
{
    if (temp)
    {
        recInorder(temp->left);
        cout << temp->item << " " << temp->height << " " << temp->balanceFactor << endl;
        recInorder(temp->right);
    }
}

void AVL::recPreorder(node *temp)
{
    if (temp)
    {
        cout << temp->item << " " << temp->height << " " << temp->balanceFactor << endl;
        recPreorder(temp->left);
        recPreorder(temp->right);
    }
}

void AVL::recPostorder(node *temp)
{
    if (temp)
    {
        recPostorder(temp->left);
        recPostorder(temp->right);
        cout << temp->item << " " << temp->height << " " << temp->balanceFactor << endl;
    }
}

void AVL::searchElement(int element)
{
    if (root == nullptr)
    {
        cout << "Tree is empty";
        return;
    }

    node *temp = root;
    while (temp)
    {
        if (temp->item == element)
        {
            cout << "Element found";
            return;
        }

        if (element < temp->item)
            temp = temp->left;
        else
            temp = temp->right;
    }
    cout << "Element not found";
}

void AVL::deleteElement(int element)
{
}

int main()
{
    AVL obj;
    obj.insertElement(70);
    obj.insertElement(40);
    obj.insertElement(90);
    obj.insertElement(100);
    obj.insertElement(120);
    // obj.insertElement(110);
    // obj.insertElement(115);

    obj.inorderTraversing();
    cout << endl;
    // obj.preTraversing();
    // cout<<endl;
    // obj.postTraversing();

    return 0;
}