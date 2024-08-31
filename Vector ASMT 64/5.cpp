#include<iostream>
#include<vector>
using namespace std;
int main()
{
    vector <int>vec1 = {0,1,2,3,4,5};
    vector <int>vec2 = {6,7,8,9};
    vector <int>vec3;

    vec3.insert(vec3.end(), vec1.begin(), vec1.begin()+3);
    vec3.insert(vec3.end(), vec2.end()-2, vec2.end());
    for(int x:vec3)
        cout<<x<<" ";

    return 0;
}