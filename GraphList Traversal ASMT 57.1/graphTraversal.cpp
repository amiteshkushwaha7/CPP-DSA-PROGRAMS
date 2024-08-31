#include <iostream>
using namespace std;
struct stackNode
{
    int vertex;
    stackNode *next;
};
class Stack
{
    private:
        stackNode *top;

    public:
        Stack():top(nullptr){}

        void push(int vertex)
        {
            stackNode *newNode = new stackNode;
            newNode->vertex = vertex;
            newNode->next = top;
            top = newNode;
        }

        int peek()
        {
            if(top == nullptr)
            {
                cout<<"Stack is empty";
                return 0;
            }
            return top->vertex;
        }

        stackNode* getTop()
        {
            return top;
        }

        void pop()
        {
            if(top == nullptr)
                cout<<"Stack is empty";
            else
            {
                stackNode *temp = top;
                top = top->next;
                temp->next = nullptr;
                delete temp;
                temp = nullptr;
            }
        }

        ~Stack()
        {
            while (top)
                pop();
        }
};

struct queueNode
{
    int vertexNum;
    queueNode *next;
};
class Queue
{
    private:
        queueNode *front;
        queueNode *rear;

    public:
        Queue():front(nullptr),rear(nullptr){}

        void insertQueue(int vertexNum)
        {
            queueNode *newNode = new queueNode;
            newNode->vertexNum = vertexNum;
            newNode->next = nullptr;

            if(front == nullptr)
            {
                front = newNode;
                rear = newNode;
            }
            else
            {
                queueNode *temp = front;
                while(temp->next)
                    temp = temp->next;
                temp->next = newNode;
                rear = newNode;
            }
        }

        void deleteQueue()
        {
            if(front == nullptr)
            {
                cout<<"Queue is empty";
                return;
            }
            else if(front == rear)
            {
                rear = nullptr;
                delete front;
                front = nullptr;
                return;
            }

            queueNode *temp = front;
            front = front->next;
            temp->next = nullptr;
            delete temp;
            temp = nullptr;
        }

        queueNode* getFront()
        {
            return front;
        }
        
        int getVertex()
        {
            return front->vertexNum;
        }

        ~Queue()
        {
            while (front)
                deleteQueue();
        }
};

struct node
{
    int vertex;
    node *next;
};
class adjList
{
private:
    node *start;

public:
    adjList() : start(nullptr) {}

    void createList(int vertex)
    {
        node *newNode = new node;
        newNode->vertex = vertex;
        newNode->next = nullptr;
        
        if(start == nullptr)
            start = newNode;
        else
        {
            node *temp = start;
            while(temp->next)
                temp = temp->next;
            temp->next = newNode;
        }
    }

    void deleteFirstNode()
    {
        if (start == nullptr)
        {
            cout << "List is empty";
            return;
        }

        node *temp = start;
        start = start->next;
        temp->next = nullptr;
        delete temp;
        temp = nullptr;
    }

    void printAdjList()
    {
        if (start == nullptr)
        {
            cout << "List is empty";
            return;
        }

        node *temp = start;
        while (temp)
        {
            cout << "V" << temp->vertex << " ";
            temp = temp->next;
        }
    }

    node* getNode()
    {
        return start;
    }

    ~adjList()
    {
        while (start)
            deleteFirstNode();
    }
};

class Graph
{
private:
    int vertex_count;
    adjList *arr;

public:
    Graph() : arr(nullptr), vertex_count(0) {}

    Graph(int vertex_count)
    {
        this->vertex_count = vertex_count;
        arr = nullptr;
    }

    void createGraph(int vertex_count)
    {
        this->vertex_count = vertex_count;

        arr = new adjList[vertex_count];
        int n, vertexNum;

        for (int i = 0; i < vertex_count; i++)
        {
            cout << endl << "How many adjacent node of V" << i << ": ";
            cin >> n;

            for (int j = 0; j < n; j++)
            {
                cout << "Enter vertex number: ";
                cin >> vertexNum;
                arr[i].createList(vertexNum);
            }
        }
    }

    void printGraph()
    {
        for(int i=0; i<vertex_count; i++)
        {
            arr[i].printAdjList();
            cout<<endl;
        }
    }

    int getVertex(node *temp)
    {
        return temp->vertex;
    }

    void BFS()
    {
        bool visited[vertex_count];
        for(int i=0; i<vertex_count; i++)
            visited[i] = false;

        node* temp = arr[0].getNode();
        int vertex = 0;

        Queue Q;
        Q.insertQueue(vertex);
        while(Q.getFront())
        {
            if(visited[vertex] == false)
            {
                while (temp)
                {
                    if(visited[temp->vertex] == false)
                        Q.insertQueue(temp->vertex);
                    temp = temp->next;
                }

                visited[vertex] = true;
                cout<<vertex <<" ";

                Q.deleteQueue();
                vertex = Q.getVertex();
                temp = arr[vertex].getNode();
            }
            else
            {
                Q.deleteQueue();
                vertex = Q.getVertex();
            }
        }
    }

    void DFS()
    {
        bool visited[vertex_count];
        for(int i=0; i<vertex_count; i++)
            visited[i] = false;

        int vertex = 0;
        node *temp = arr[0].getNode();

        Stack S;
        S.push(vertex);
        while (S.getTop())
        {
            if(visited[vertex] == false)
            {
                visited[vertex] = true;
                cout<<vertex <<" ";
                S.pop();
                while (temp)
                {
                    if(visited[temp->vertex] == false)
                        S.push(temp->vertex);
                    temp = temp->next;
                }
                
                vertex = S.peek();
                temp = arr[vertex].getNode();
            }
            else
            {
                S.pop();
                vertex = S.peek();
            }
        }
    }

    ~Graph()
    {
        delete[] arr;
        arr = nullptr;
    }
};

int main()
{
    Graph graph;
    graph.createGraph(5);
    //graph.printGraph();
    //graph.BFS();
    cout<<endl;
    graph.DFS();
    return 0;
}