#include<iostream>
using namespace std;
template <typename T>
void printArray(T arr[], int n)
{
    for(int i=0; i<n; i++)
        cout<<arr[i] <<" ";
}

template <typename T>
void sortArray(T arr[], int n)
{
    T min,k;
    int temp;
    for(int i=0; i<n-1; i++)
    {
        min = arr[i];
        temp = i;
        for(int j=i+1; j<n; j++)
        {
            if(min>arr[j])
            {
                min = arr[j];
                temp = j;
            }
        }
        k = arr[i];
        arr[i] = min;
        arr[temp] = k;
    }
}
int main()
{
    int array[10] = {2,5,4,1,3,8,6,7,0,9};
    sortArray(array , 10);
    printArray(array, 10);
    return 0;
}