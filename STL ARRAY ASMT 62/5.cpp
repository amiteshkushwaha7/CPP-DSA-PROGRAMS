#include<iostream>
#include<array>
using namespace std;
void sortArray(array <int,5>&arr)
{
    int temp;
    for(int i=0; i<5; i++)
    {
        temp = i;
        for(int j=i+1; j<5; j++)
        {
            if(arr[temp]>arr[j])
                temp = j;

            swap(arr[temp],arr[i]);
        }
        
    }
}

int main()
{
    array <int,5>A = {0,3,4,2,1};
    
    sortArray(A);

    array<int,5>::iterator i;
    for(i=A.begin(); i!=A.end(); i++)
        cout<<*i<<" ";

    return 0;
}

