#include <iostream>
using namespace std;
class Heap
{
private:
    int capacity;
    int lastIndex;
    int *ptr;

public:
    Heap() : capacity(0), lastIndex(-1), ptr(nullptr) {}

    Heap(int capacity)
    {
        this->capacity = capacity;
        this->lastIndex = -1;

        ptr = new int[capacity];
    }

    void createHeap(int);
    void insertHeap(int);
    void deleteHeap();
    void displayHeap();
    void isEmptyHeap();
    void sortHeap();
    void linearSearch(int);
    int binarySearch(int, int, int);
    int getElement();

    ~Heap(){delete []ptr;}
};

int Heap::getElement()
{ return ptr[0];}

void Heap::createHeap(int capacity)
{
    if (ptr != nullptr)
        delete[] ptr;

    this->capacity = capacity;
    this->lastIndex = -1;

    ptr = new int[capacity];
}

void Heap::insertHeap(int element)
{
    if(lastIndex == capacity-1)
    {
        cout<<"Heap is full";
        return;
    }

    lastIndex++;
    ptr[lastIndex] = element;

    if(ptr[lastIndex] > ptr[(lastIndex-1)/2])
    {
        int k, tempIndex = lastIndex;

        while (ptr[tempIndex] > ptr[(tempIndex-1)/2])
        {
            k = ptr[tempIndex];
            ptr[tempIndex] = ptr[(tempIndex-1)/2];
            ptr[(tempIndex-1)/2] = k;
            tempIndex = (tempIndex-1)/2;

        }
    }
}

void Heap::deleteHeap()
{
    if(lastIndex == -1)
    {
        cout<<"Heap is empty";
        return;
    }

    int k,tempIndex,delData;

    delData = ptr[0];
    k = ptr[0];
    ptr[0] = ptr[lastIndex];
    ptr[lastIndex] = k;
    lastIndex = lastIndex-1;;
    tempIndex = 0;

    while((ptr[tempIndex] < ptr[(2*tempIndex)+1]) || (ptr[tempIndex] < ptr[(2*tempIndex)+2]))
    {
        if((2*tempIndex)+1 > lastIndex)
            return;

        if((ptr[(2*tempIndex)+1] > ptr[(2*tempIndex)+2]))
        {
            if(ptr[(2*tempIndex)+1] != delData)
            {
                k = ptr[tempIndex];
                ptr[tempIndex] = ptr[(2*tempIndex)+1];
                ptr[(2*tempIndex)+1] = k;
                tempIndex = (2*tempIndex)+1;
            }
            else
            {
                k = ptr[tempIndex];
                ptr[tempIndex] = ptr[(2*tempIndex)+2];
                ptr[(2*tempIndex)+2] = k;
                tempIndex = (2*tempIndex)+2;
            }
        }
        else
        {
            if(ptr[(2*tempIndex)+2] != delData)
            {
                k = ptr[tempIndex];
                ptr[tempIndex] = ptr[(2*tempIndex)+2];
                ptr[(2*tempIndex)+2] = k;
                tempIndex = (2*tempIndex)+2;
            }
            else
            {
                k = ptr[tempIndex];
                ptr[tempIndex] = ptr[(2*tempIndex)+1];
                ptr[(2*tempIndex)+1] = k;
                tempIndex = (2*tempIndex)+1;
            }
        }
    }
}

void Heap::isEmptyHeap()
{
    if(lastIndex == -1)
    {
        cout<<"Heap is empty";
        return;
    }
    else 
        cout<<"Heap is not empty";
        
}

void Heap::displayHeap()
{
    for (int i = 0; i <= lastIndex; i++)
        cout<<ptr[i] <<" ";
    
}

void Heap::sortHeap()
{
    int j = lastIndex;
    for(int i=1; i<=j; i++)
        deleteHeap();
    lastIndex = j;
}

void Heap::linearSearch(int element)
{
    bool flag = false;
    for(int i=0; i<=lastIndex; i++)
    {
        if(ptr[i]==element)
        {
            flag = true;
            cout<<"Element found at index "<<i;
            break;
        }
    }

    if(flag == false)
        cout<<"Element not found";
}

int Heap::binarySearch(int element, int start, int end)
{
    int m;
    m = (start+end)/2;

    if(ptr[m]==element)
        return m;
    
    if(start>=end)
        return -1;

    if(element < ptr[m])
        binarySearch(element, start, m-1);
    else
        binarySearch(element, m+1, end);
}

int main()
{
    int array[] = {20,35,70,14,60,80,54,72,30,44,53,10};

    Heap heap;
    heap.createHeap(12);
    for(int i=0; i<12; i++) 
        heap.insertHeap(array[i]);

    heap.displayHeap();
    heap.sortHeap();
    cout<<endl;
    heap.displayHeap();

    int index = heap.binarySearch(555, 0, 11);
    if(index == -1)
        cout<<"Data not found";
    else
        cout<<"Element is at index "<<index;
    
    return 0;
}