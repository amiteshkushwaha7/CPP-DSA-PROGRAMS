#include<iostream>
#include<vector>
using namespace std;
void insert(vector <int>&V)
{
    V.insert(V.end()-1,3,25);
}

int main()
{
    vector <int>vec = {1,2,3};
    insert(vec);
    for(int i:vec)
        cout<<i<<" ";
    return 0;
}