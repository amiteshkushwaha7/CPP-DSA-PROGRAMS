#include<iostream>
#include<vector>
using namespace std; 
int main()
{
    vector <string>vec = {"Amitesh","Rajan","Ankur","Dheeraj","Shiva"};
    for(string str:vec)  
        cout<<str<<" ";

    return 0;
}