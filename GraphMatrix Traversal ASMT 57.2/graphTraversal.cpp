#include<iostream>
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
            if(front == nullptr)
                return 0;
            return front->vertexNum;
        }

        ~Queue()
        {
            while (front)
                deleteQueue();
        }
};

class Graph
{
    private:  
        int vertex_count;
        int edge_count;
        int **adj;

    public:
        Graph():vertex_count(0),edge_count(0),adj(nullptr){}

        Graph(int vertex_count, int edge_count)
        {
            this->vertex_count = vertex_count;
            this->edge_count = edge_count;
            adj = nullptr;
        }

        void createGraph(int vertex_count, int edge_count)
        {
            if(adj != nullptr)
                adj = nullptr;
            
            this->vertex_count = vertex_count;
            this->edge_count = edge_count;

            adj = new int*[vertex_count];
            for(int i=0; i<vertex_count; i++)
                adj[i] = new int[vertex_count];

            for(int i=0; i<vertex_count; i++)
            {
                for(int j=0; j<vertex_count; j++)
                    adj[i][j] = 0;
            }

            int n,vertexNum;
            for(int i=0; i<vertex_count; i++)
            {
                cout<<endl<<"How many adjacent of V"<<i <<": ";
                cin>>n;

                for(int j=1; j<=n; j++)
                {
                    cout<<"Enter vertex: ";
                    cin>>vertexNum;

                    adj[i][vertexNum] = 1;
                }
            }
        }

        void printGraph()
        {
            for(int i=0; i<vertex_count; i++)
            {
                for(int j=0; j<vertex_count; j++)
                    cout<<adj[i][j] <<" ";
                cout<<endl;
            }
        }

        void BFS()
        {
            bool visited[vertex_count];
            for(int i=0; i<vertex_count; i++)
                visited[i] = false;

            int V = 0;
            
            Queue Q;
            Q.insertQueue(V);

            while (Q.getFront())
            {
                if(visited[V] == false)
                {
                    visited[V] = true;
                    cout<<V <<" ";
                    Q.deleteQueue();

                    for(int i=0; i<vertex_count; i++)
                    {
                        if(adj[V][i] == 1 && visited[i] == false)
                            Q.insertQueue(i);
                    }

                    V = Q.getVertex();
                }
                else
                {
                    Q.deleteQueue();
                    V = Q.getVertex();
                }
            }   
        }

        void DFS()
        {
            bool visited[vertex_count];
            for(int i=0; i<vertex_count; i++)
                visited[i] = false;

            int V = 0;

            Stack S;
            S.push(V);
            while (S.getTop())
            {
                if(visited[V] == false)
                {
                    visited[V] = true;
                    cout<<V <<" ";
                    S.pop();
                    for(int i=0; i<vertex_count; i++)
                    {
                        if(adj[V][i] == 1 && visited[i] == false)
                            S.push(i);
                    }

                    V = S.peek();
                }
                else
                {
                    S.pop();
                    V = S.peek();
                }
            }
            
        }
};

int main()
{
    Graph graph;
    graph.createGraph(4,4);
    graph.printGraph();
    cout<<endl;
    graph.BFS();
    //graph.DFS();
    return 0;
}