#include<iostream>
#include<vector>
using namespace std;
void deleteVector(vector <int>&V)
{
    vector <int>::iterator it;
    for(int i=0; i<V.size(); i++)
    {
        if(V[i]<0)
        {
            it = V.begin()+i;
            break;
        }
    }

    V.erase(it,V.end());
    for(int i:V)
        cout<<i<<" ";
}

int main()
{
    vector <int>vec = {3,4,2,1,5,-3,7,6,8,9,0};
    deleteVector(vec);
    return 0;
}