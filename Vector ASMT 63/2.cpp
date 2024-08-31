#include<iostream>
#include<vector>
using namespace std;
int main()
{
    vector <float>vec = {1.1,2.2,3.3,4.4,5.5};
    for(int i=0; i<vec.size(); i++)
        cout<<vec.at(i)<<" ";

    return 0;
}