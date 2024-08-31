#include<iostream>
#include<vector>
using namespace std;
vector<int> findSmallers(vector <int>&V)
{
    vector <int>res;
    vector <int>::iterator it;

    for(it=V.begin()+1; it!=V.end()-1; it++)
    {
        if(*it<*(it-1) && *it<*(it+1))
            res.push_back(*it);
    }
    cout<<res.capacity()<<endl;
    cout<<res.size()<<endl;


    return res;
}

int main()
{
    vector <int>vec = {15,9,11,10,12};
    vector <int>result = findSmallers(vec);
    // cout<<result.size()<<endl;
    // cout<<result.capacity()<<endl;

    for(int i:result)
        cout<<i<<" ";

    return 0;
}