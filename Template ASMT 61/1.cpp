#include<iostream>
using namespace std;
template<typename datatype>
datatype big(datatype a, datatype b)
{
    if(a>b)
        return a;
    return b;
}

int main()
{
    cout<<big(4,5)<<endl;
    cout<<big(4.5, 5.5)<<endl;
    cout<<big("Ankur","Amitesh")<<endl;
    return 0;
}