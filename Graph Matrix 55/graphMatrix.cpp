#include <iostream>
using namespace std;
class Graph
{
private:
    int vertex_count;
    int edge_count;
    int **adj;

public:
    Graph() : adj(nullptr),vertex_count(0),edge_count(0) {}

    void createGraph(int vertex_count, int edge_count)
    {
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

        int n,num;
        for(int i=0; i<vertex_count; i++)
        {
            cout<<endl<<"How many adjacent node of V"<<i <<": ";
            cin>>n;
            for(int j=1; j<=n; j++)
            {
                cout<<"Enter " <<j <<"vertex number: ";
                cin>>num;
                adj[i][num] = 1;
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

    void printAdjacentNodes(int x)
    {
        for(int i=0; i<vertex_count; i++)
        {
            if(adj[x][i] == 1)
                cout<<"V"<<i <<" ";
        }
    }

    void isIsolated(int x)
    {
        int flag = 0;
        for(int i=0; i<vertex_count; i++)
        {
            if(adj[x][i] == 1)
            {
                flag = 1;
                break;
            }
        }

        if(flag == 0)
            cout<<"Node is isolated";
        else
            cout<<"Node is not isolated";
    }
    
    ~Graph()
    {
        for(int i=0; i<vertex_count; i++)
            delete []adj[i];

        delete []adj;
    }
};

int main()
{
    Graph graph;
    graph.createGraph(4,4);
    graph.printGraph();
    graph.printAdjacentNodes(2);
    return 0;
}