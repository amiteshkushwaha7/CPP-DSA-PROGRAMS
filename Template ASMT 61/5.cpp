#include <iostream>
#include <string.h>
using namespace std;
template <typename T>
class dynamicArray
{
private:
    int capacity;
    int lastIndex;
    T *ptr;

public:
    // Parameterized Constructor to initialize capacity & create dynamic array
    dynamicArray(int size)
    {
        capacity = size;
        ptr = new T[capacity];
        lastIndex = -1;
    }

    // Copy constructor for deep copy
    dynamicArray(dynamicArray &arr)
    {
        capacity = arr.capacity;
        lastIndex = arr.lastIndex;
        ptr = new T[capacity];
        for (int i = 0; i <= lastIndex; i++)
            ptr[i] = arr.ptr[i];
    }

    // Copy assignment operator for deep copy
    dynamicArray &operator=(dynamicArray &arr)
    {
        capacity = arr.capacity;
        lastIndex = arr.lastIndex;

        if (ptr != nullptr)
            delete[] ptr;

        ptr = new T[capacity];
        for (int i = 0; i <= lastIndex; i++)
            ptr[i] = arr.ptr[i];
        return (*this);
    }

    // Desctructor
    ~dynamicArray() { delete[] ptr; }

    // Method to double the size of array
    void doubleArray();

    // Method to half the size of array
    void halfArray();

    // Method to return the current capacity of array
    int arrayCapacity();

    // Method to return lastIndex of array
    int LastIndex();

    // Method to check array is empty or not
    bool checkArray_isEmptyorNot();

    // Method to append a new element in the array
    void appendElement(T);

    // Method to insert a new element at specific index
    void insertSpecificElement(int, T);

    // Method to edit/update an element at specific index
    void editElement(int, T);

    // Method to delete an element at specific index
    void deleteElement(int, T);

    // Method to check array is full or not
    bool checkArray_isFullorNot();

    // Method to get an element at specific index
    T getElemnt(int);

    // Method to count total valid element present in array
    int countElements();

    // Method to find given element in array
    int findElement(T);

    // Method to display array
    void displayArray();

    // Metho to sort elements of the array
    void sortArray();

    // Method to find the greatest element in the array
    T findGreatestElement();

    // Method to find the smallest element in the array
    T findSmallestElement();

    // Method search an element in the array
    void searchElement(T);

    // Method to calculate sum of all the elements of an array
    T calculateSum();

    // Method to calculate average of all the elements of an array
    float calcuateAverage();

    // Method to rotate an array towards right by one position
    void rotateArray(char, int);

    // Method to remove duplicate elements in the array
    void removeDuplicateElements();

    // Method to find the second largest element in the array
    T secondLargesElement();

    // Method to swap elements with specified indices in the array
    void swapElements(int, int);
};

template <typename T>
void dynamicArray<T>::doubleArray()
{
    T *temp;
    temp = new T[capacity*2];
    for(int i=0; i<=lastIndex; i++)
        temp[i] = ptr[i];

    delete [] ptr;
    ptr = temp;
    delete [] temp;
    capacity = capacity * 2;
    cout<<"Array capacity has been double!";
}

template <typename T>
void dynamicArray<T>::halfArray()
{
    T *temp;
    temp = new T[(capacity/2)+1];
    for(int i=0; i<=lastIndex; i++)
        temp[i] = ptr[i];


    delete [] ptr;
    ptr = temp;
    delete [] temp;
    capacity = (capacity/2) + 1;
    cout<<"Array capacity has been half!";
}

template <typename T>
int dynamicArray<T>::arrayCapacity()
{
    return capacity;
}

template <typename T>
int dynamicArray<T>::LastIndex()
{
    return lastIndex;
}

template <typename T>
bool dynamicArray<T>::checkArray_isEmptyorNot()
{
    if (lastIndex == -1)
        return true;
    return false;
}

template <typename T>
void dynamicArray<T>::appendElement(T element)
{
    if (lastIndex < (capacity - 1))
    {
        ptr[lastIndex + 1] = element;
        lastIndex++;
    }
    else
        cout << "Array is full! ";
}

template <typename T>
void dynamicArray<T>::insertSpecificElement(int index, T element)
{
    if (lastIndex == (capacity - 1))
        cout << "Array is already full!";
    else if (index > lastIndex)
        cout << "Element can't insert, enter valid contiguous index";
    else
    {
        for (int i = lastIndex; i >= index; i--)
        {
            ptr[i + 1] = ptr[i];
        }

        ptr[index] = element;
        lastIndex++;
    }
}

template <typename T>
void dynamicArray<T>::editElement(int index, T element)
{
    if (index > lastIndex)
        cout << "Element can't edit, enter valid contiguous index";
    else
    {
        ptr[index] = element;
        cout << "Element updation successfull";
    }
}

template <typename T>
void dynamicArray<T>::deleteElement(int index, T element)
{
    T j;
    if (lastIndex == -1)
        cout << "Array is not initialized!";
    else if (index == lastIndex)
        lastIndex--;
    else if (index > lastIndex)
        cout << "Garbage value of this index has been deleted!";
    else
    {
        for (int i = index; i < lastIndex; i++)
        {
            j = ptr[i];
            ptr[i] = ptr[i + 1];
            ptr[i + 1] = j;
        }
        lastIndex--;
    }
}

template <typename T>
bool dynamicArray<T>::checkArray_isFullorNot()
{
    if (lastIndex == (capacity - 1))
        return true;
    else
        return false;
}

template <typename T>
T dynamicArray<T>::getElemnt(int index)
{
    if (lastIndex == -1 || index > lastIndex)
        return T();
    else
        return ptr[index];
}

template <typename T>
int dynamicArray<T>::countElements()
{
    return (lastIndex + 1);
}

template <typename T>
int dynamicArray<T>::findElement(T element)
{
    for (int i = 0; i <= lastIndex; i++)
    {
        if (ptr[i] == element)
            return i;
    }

    return -1;
}

template <typename T>
void dynamicArray<T>::displayArray()
{
    for (int i = 0; i <= lastIndex; i++)
        cout << ptr[i] << " ";
}

template <typename T>
void dynamicArray<T>::sortArray()
{
    if (lastIndex == -1)
        cout << "Array is not initialized!";
    else
    {
        int i, j, k, temp;
        T min;
        for (i = 0; i <= lastIndex; i++)
        {
            min = ptr[i];
            temp = i;
            for (j = i + 1; j <= lastIndex; j++)
            {
                if (ptr[j] < min)
                {
                    min = ptr[j];
                    temp = j;
                }
            }
            k = ptr[i];
            ptr[i] = ptr[temp];
            ptr[temp] = k;
        }
        cout << "Array sorting successful!";
    }
}

template <typename T>
T dynamicArray<T>::findGreatestElement()
{
    if (lastIndex == -1)
    {
        cout << "Array is not initialized!";
        return T();
    }
    else
    {
        int j, k;
        T max;
        max = ptr[0];
        for (j = 1; j <= lastIndex; j++)
        {
            if (ptr[j] > max)
                max = ptr[j];
        }
        return max;
    }
}

template <typename T>
T dynamicArray<T>::findSmallestElement()
{
    if (lastIndex == -1)
    {
        cout << "Array is not initialized!";
        return T();
    }
    else
    {
        int j, k;
        T min;
        min = ptr[0];
        for (j = 1; j <= lastIndex; j++)
        {
            if (ptr[j] < min)
                min = ptr[j];
        }
        return min;
    }
}

template <typename T>
void dynamicArray<T>::searchElement(T element)
{
    if (lastIndex == -1)
        cout << "Array is not initialized!";
    else
    {
        int flag = 0;
        for (int i = 0; i <= lastIndex; i++)
        {
            if (ptr[i] == element)
            {
                flag = 1;
                cout << "Element " << element << " is at index " << i;
            }
        }

        if (flag == 0)
            cout << "Element not found!";
    }
}

template <typename T>
T dynamicArray<T>::calculateSum()
{
    if (lastIndex == -1)
    {
        cout << "Array is not initialized!";
        return T();
    }
    else
    {
        T sum = 0;
        for (int i = 0; i <= lastIndex; i++)
            sum = sum + ptr[i];

        return sum;
    }
}

template <typename T>
float dynamicArray<T>::calcuateAverage()
{
    if (lastIndex == -1)
    {
        cout << "Array is not initialized!";
        return T();
    }
    else
    {
        T sum = 0;
        float average;
        for (int i = 0; i <= lastIndex; i++)
            sum = sum + ptr[i];

        average = sum / lastIndex + 1;
        return average;
    }
}

template <typename T>
void dynamicArray<T>::rotateArray(char direction, int position)
{
    if (lastIndex == -1)
        cout << "Array is not initialized!";
    else
    {
        if (direction == 'l')
        {
            T k;
            for (int i = 1; i <= position; i++)
            {
                k = ptr[0];
                for (int j = 0; j <= lastIndex; j++)
                    ptr[j] = ptr[j + 1];

                ptr[lastIndex] = k;
            }
        }
        else
        {
            T k;
            for (int i = 1; i <= position; i++)
            {
                k = ptr[lastIndex];
                for (int j = lastIndex; j >= 0; j--)
                    ptr[j] = ptr[j - 1];

                ptr[0] = k;
            }
        }
        cout << "Sifting successfull!";
    }
}

template <typename T>
void dynamicArray<T>::removeDuplicateElements()
{
    if (lastIndex == -1)
        cout << "Array is not initialized!";
    else
    {
        for (int i = 0; i <= lastIndex; i++)
        {
            for (int j = i + 1; j <= lastIndex; j++)
            {
                if (ptr[j] == ptr[i])
                    deleteElement(j, ptr[j]);
            }
        }
        cout << "All duplicate elements has been deleted!";
    }
}

template <typename T>
T dynamicArray<T>::secondLargesElement()
{
    if (lastIndex == -1)
    {
        cout << "Array is not initialized!";
        return T();
    }
    else
    {
        int k, temp1, temp2, maxTemp;
        T max, min;
        for (int i = 1; i <= 2; i++)
        {
            max = ptr[0];
            min = ptr[0];
            for (int j = 1; j <= lastIndex; j++)
            {
                if (ptr[j] > max)
                {
                    max = ptr[j];
                    temp1 = j;
                }

                if (ptr[j] < min)
                {
                    min = ptr[j];
                    temp2 = j;
                }
            }

            if (i == 1)
            {
                maxTemp = temp1;
                k = ptr[maxTemp];
                ptr[maxTemp] = min;
            }
        }

        ptr[maxTemp] = k;
        return max;
    }
}

template <typename T>
void dynamicArray<T>::swapElements(int index1, int index2)
{
    if (lastIndex == -1)
        cout << "Array is not intialized!";
    else if (index1 > lastIndex && index2 > lastIndex)
        cout << "Invalid Indecies: Greater than array size";
    else if (index1 > lastIndex)
        cout << "Invalid Index1: Greater than array size";
    else if (index2 > lastIndex)
        cout << "Invalid Index2: Greater than array size";
    else
    {
        T i;
        i = ptr[index1];
        ptr[index1] = ptr[index2];
        ptr[index2] = i;
        cout << "Elements swaped.";
    }
}

int menu()
{
    int choice;
    cout <<endl << endl <<"-2.Double the size of array"<<endl;
    cout <<"-1.Half the size of array"<<endl;
    cout <<"0.Check current capacity of array"<<endl;
    cout << "1.Check array is empty or not" << endl;
    cout << "2.Append new element" << endl;
    cout << "3.Insert new element at specific index" << endl;
    cout << "4.Edit element at specific index" << endl;
    cout << "5.Delete element at specific index" << endl;
    cout << "6.Check array is full or not" << endl;
    cout << "7.Get element at specific index" << endl;
    cout << "8.Count number of element in array" << endl;
    cout << "9.Find element in array" << endl;
    cout << "10.Display array" << endl;
    cout << "11.Sort element of array" << endl;
    cout << "12.Find the greatest element in array" << endl;
    cout << "13.Find the smallest element in array" << endl;
    cout << "14.Search an element in array" << endl;
    cout << "15.Calculate sum of all array's elements" << endl;
    cout << "16.Calculate average of all array's elements" << endl;
    cout << "17.Rotate an array towards direction and position" << endl;
    cout << "18.Remove duplicate element in the array" << endl;
    cout << "19.Find the seconde largest element in the array" << endl;
    cout << "20.Swap element with specified indices in the array" << endl;
    cout << "21.Exit program" << endl << endl;

    cout << "Enter your choice: ";
    cin >> choice;

    return choice;
}

int main()
{
    int size;
    cout << "Enter the size of array: ";
    cin >> size;
    dynamicArray <int>array(size);

    while (true)
    {
        switch (menu())
        {
        case -2:
            int Lindx, Acap;
            Lindx = array.LastIndex();
            Acap = array.arrayCapacity();

            if(Lindx == Acap-1)
                array.doubleArray();
            else
                cout<<"Can't double: Current array is not full!"; 
            break;

        case -1:
            int u,v,w;
            u = array.LastIndex();
            v = array.arrayCapacity();
            if(u >= (v/2))
                cout<<"Number of array's element is greater than half array capacity";
            else
                array.halfArray();
            break;

        case 0:
            cout<<"Current array capacity = "<<array.arrayCapacity();
            break;

        case 1:
            bool b;
            b = array.checkArray_isEmptyorNot();
            if (b == true)
                cout << "Array is empty!";
            else
                cout << "Array is not empty!";
            break;

        case 2:
            int element;
            cout << "Enter an element: ";
            cin >> element;
            array.appendElement(element);
            break;

        case 3:
            int indx;
            int Elmnt;
            cout << "Enter index(0 to " << size - 1 << ")-> ";
            cin >> indx;
            cout << "Entet element: ";
            cin >> Elmnt;

            array.insertSpecificElement(indx, Elmnt);
            break;

        case 4:
            int index;
            int Element;
            cout << "Enter index(0 to " << size - 1 << ")-> ";
            cin >> index;
            cout << "Entet element: ";
            cin >> Element;

            array.editElement(index, Element);
            break;

        case 5:
            int ind;
            int Elmt;
            cout << "Enter index(0 to " << size - 1 << ")-> ";
            cin >> ind;
            cout << "Entet element: ";
            cin >> Elmt;

            array.deleteElement(ind, Elmt);
            break;

        case 6:
            bool x;
            x = array.checkArray_isFullorNot();
            if (x == true)
                cout << "Array is full!";
            else
                cout << "Array is not full";
            break;

        case 7:
            int i, Index;
            cout << "Enter index(0 to " << size - 1 << ")-> ";
            cin >> Index;

            i = array.getElemnt(Index);
            if (i == 0)
                cout << "Array is not initialized!";
            else
                cout << i;
            break;

        case 8:
            cout << array.countElements();
            break;

        case 9:
            int I;
            int ELEMENT;
            cout << "Enter an element:";
            cin >> ELEMENT;

            I = array.findElement(ELEMENT);
            if (I == -1)
                cout << "Element not found!";
            else
                cout << "Element index: " << I;
            break;

        case 10:
            array.displayArray();
            break;

        case 11:
            array.sortArray();
            break;

        case 12:
            cout << "Greatest element of array: " << array.findGreatestElement();
            break;

        case 13:
            cout << "Smallest element of array: " << array.findSmallestElement();
            break;

        case 14:
            int e;
            cout << "Enter an element: ";
            cin >> e;
            array.searchElement(e);
            break;

        case 15:
            cout << "Sum = " << array.calculateSum();
            break;

        case 16:
            cout << "Average = " << array.calcuateAverage();
            break;

        case 17:
            char direction;
            int position;
            cout << "Enter direction(l/r): ";
            cin >> direction;
            cout << "Enter position: ";
            cin >> position;
            array.rotateArray(direction, position);
            break;

        case 18:
            array.removeDuplicateElements();
            break;

        case 19:
            cout << "Second largest element = " << array.secondLargesElement();
            break;

        case 20:
            int x1, y1;
            cout << "Enter two index(0to" << size - 1 << ")-> ";
            cin >> x1 >> y1;
            array.swapElements(x1, y1);
            break;

        case 21:
            cout << "Program has been ended!";
            exit(0);

        default:
            cout << "Invalid Choice";
            exit(0);
        }
    }

    return 0;
}