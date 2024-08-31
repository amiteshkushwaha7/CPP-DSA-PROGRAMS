#include <iostream>
using namespace std;
struct node
{
    int vertexNum;
    int vertexData;
    node *next;
};

class AdjList
{
private:
    int vertexList;
    node *start;

public:
    //Constructor
    AdjList() : start(nullptr) {}

    //Parameterized constructor
    AdjList(int vertexList)
    {
        this->vertexList = vertexList;
        start = nullptr;
    }

    //Method to set vertexList
    void setVertexList(int listNumber)
    {
        vertexList = listNumber;
    }

    //Method to get vertex number
    int getVertex()
    {
        return vertexList;
    }

    //Method to create list
    void addNode(int vertexNum, int vertexData)
    {
        node *newNode = new node;
        newNode->vertexNum = vertexNum;
        newNode->vertexData = vertexData;
        newNode->next = nullptr;

        if (start == nullptr)
            start = newNode;
        else
        {
            node *temp = start;
            while (temp->next)
                temp = temp->next;

            temp->next = newNode;
        }
    }

    //Method to display list
    void displayList()
    {
        if(start == nullptr)
        {
            cout<<"List is empty";
            return;
        }
        node *temp = start;
        while(temp)
        {
            cout<<"V"<<temp->vertexNum <<":"<<temp->vertexData <<" ";
            temp = temp->next;
        }
    }

    //Method to delete a list node
    void deleteList()
    {
        if (start == nullptr)
            cout << "List is empty";
        else if (start->next == nullptr)
        {
            delete start;
            start = nullptr;
        }
        else
        {
            node *temp = start, *prev = nullptr;
            while (temp->next)
            {
                prev = temp;
                temp = temp->next;
            }

            prev->next = nullptr;
            delete temp;
        }
    }

    //Distructor
    ~AdjList()
    {
        while(start)
            deleteList();
    }
};

class Graph
{
private:
    int vertex_count;
    AdjList *arr;

public:
    //Non-Parameterized constructor
    Graph() : arr(nullptr), vertex_count(0) {}

    //Method to create graph
    void createGraph(int vertex_count)
    {
        if(arr != nullptr)
            arr = nullptr;
        
        this->vertex_count = vertex_count;
        arr = new AdjList[vertex_count];

        int n, vertexNum, vertexData;
        for(int i=0; i<vertex_count; i++)
        {
            arr[i].setVertexList(i);
            cout<<endl<<"How many adjacent node of V"<<i <<": ";
            cin>>n;

            for(int j=0; j<n; j++)
            {
                cout<<"Enter vertex number: ";
                cin>>vertexNum;
                cout<<"Enter vertex data: ";
                cin>>vertexData;
                arr[i].addNode(vertexNum, vertexData);
            }
        }
    }

    //Method to add new node in list
    void addEdge()
    {
        int vertexNum, newVertex;
        cout<<"Enter vertex number: ";
        cin>>vertexNum;
        cout<<"Enter connected vertex number: ";
        cin>>newVertex;

        arr[vertexNum].addNode(newVertex, 10*newVertex);
        arr[newVertex].addNode(vertexNum, 10*vertexNum);
    }

    //Method to print graph
    void printGraph()
    {
        for(int i=0; i<vertex_count; i++)
        {
            cout<<"V"<<arr[i].getVertex() <<"-> ";
            arr[i].displayList();
            cout<<endl;
        }
    }

    //Distructor
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
    graph.printGraph();
    cout<<endl <<endl;
    graph.addEdge();
    graph.printGraph();
    
    return 0;
}
