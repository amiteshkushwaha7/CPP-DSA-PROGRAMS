#include<iostream>
#include<vector>
using namespace std;
int is_Prime(int n, int i)
{
    if(n==0 || n==1)
        return 0;

    if(i==n)
        return 1;
        
    if(n%i==0)
        return -1;
    else 
        is_Prime(n,i+1);
}

void deletePrime(vector <int>&V)
{
    int x;
    for(int i=0; i<V.size(); i++)
    {
        x = is_Prime(V[i],V[i]-1);
        if(x==1)
            V.erase(V.begin()+i);
    }
}

int main()
{
    vector <int>vec = {0,1,2,5,4,3,6,7,8,9,10,11,12,13,14,15};

    deletePrime(vec);

    for(int x:vec)
        cout<<x<<" ";

    return 0;
}