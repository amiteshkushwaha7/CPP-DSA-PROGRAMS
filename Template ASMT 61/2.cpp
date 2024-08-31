#include<iostream>
using namespace std;
template <typename T>
void printArray(T arr[], int n)
{
    for(int i=0; i<n; i++)
        cout<<arr[i] <<" ";
}
int main()
{
    int array[10] = {1,2,3,4,5,6,7,8,9,0};
    printArray(array , 10);
    return 0;
}