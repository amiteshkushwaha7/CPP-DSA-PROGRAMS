#include<iostream>
#include<vector>
using namespace std;
int main()
{
    vector <int> data = {2,4,10,5,7,6,15,20,3,9};
    vector <vector<int>> v;
    vector <int>::iterator it;
    int i=0;
    for(it=data.begin(); it!=data.end(); it++)
    {
        if(v.size()==0)
            v.push_back({});

        if(*it < *(it+1))
        {
            v[i].push_back(*it);
        }
        else
        {
            v[i].push_back(*it);
            v.push_back(vector <int>());
            i++;
        }
    }

    for(i=0; i<v.size(); i++)
    {
        for(auto x:v[i])
            cout<<x<<" ";
        cout<<endl;
    }

    return 0;
}