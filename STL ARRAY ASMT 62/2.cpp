#include<iostream>
#include<array>
using namespace std;
int main()
{
    array <float,5>A = {5.5,1.1,2.2,3.3,4.4};

    array<float,5>::iterator i;
    float sum=0;
    for(i=A.begin(); i!=A.end(); i++)
        sum = sum + *i;
    
    float avg = sum/5;
    cout<<avg;

    return 0;
}