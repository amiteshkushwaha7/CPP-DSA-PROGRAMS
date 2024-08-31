#include<iostream>
#include<array>
using namespace std;
int main()
{
    array <int,5>A;

    array<int,5>::iterator i;
    cout<<"Enter array inputs";
    for(i=A.begin(); i!=A.end(); ++i)
        cin>>*i;
    
    int max=0;
    for(int m : A)
    {
        if(m > max)
            max = m;
    }
    cout<<max;
    return 0;
}