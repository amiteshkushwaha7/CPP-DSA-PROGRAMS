#include <iostream>
#include <string.h>
using namespace std;
class Array
{
private:
    int capacity;
    int lastIndex;
    int *ptr;

public:
    // Parameterized Constructor to initialize capacity & create dynamic array
    Array(int size)
    {
        capacity = size;
        ptr = new int[capacity];
        lastIndex = -1;
    }

    // Copy constructor for deep copy
    Array(Array &arr)
    {
        capacity = arr.capacity;
        lastIndex = arr.lastIndex;
        ptr = new int[capacity];
        for (int i = 0; i <= lastIndex; i++)
            ptr[i] = arr.ptr[i];
    }

    // Copy assignment operator for deep copy
    Array &operator=(Array &arr)
    {
        capacity = arr.capacity;
        lastIndex = arr.lastIndex;

        if (ptr != nullptr)
            delete[] ptr;

        ptr = new int[capacity];
        for (int i = 0; i <= lastIndex; i++)
            ptr[i] = arr.ptr[i];
        return (*this);
    }

    // Desctructor
    ~Array() { delete[] ptr; }

    // Method to check array is empty or not
    bool checkArray_isEmptyorNot();

    // Method to append a new element in the array
    void appendElement(int);

    // Method to insert a new element at specific index
    void insertSpecificElement(int, int);

    // Method to edit/update an element at specific index
    void editElement(int, int);

    // Method to delete an element at specific index
    void deleteElement(int, int);

    // Method to check array is full or not
    bool checkArray_isFullorNot();

    // Method to get an element at specific index
    int getElemnt(int);

    // Method to count total valid element present in array
    int countElements();

    // Method to find given element in array
    int findElement(int);

    // Method to display array
    void displayArray();

    // Metho to sort elements of the array
    void sortArray();

    // Method to find the greatest element in the array
    int findGreatestElement();

    // Method to find the smallest element in the array
    int findSmallestElement();

    // Method search an element in the array
    void searchElement(int);

    // Method to calculate sum of all the elements of an array
    int calculateSum();

    // Method to calculate average of all the elements of an array
    float calcuateAverage();

    // Method to rotate an array towards right by one position
    void rotateArray(char, int);

    // Method to remove duplicate elements in the array
    void removeDuplicateElements();

    // Method to find the second largest element in the array
    int secondLargesElement();

    // Method to swap elements with specified indices in the array
    void swapElements(int, int);
};

bool Array::checkArray_isEmptyorNot()
{
    if (lastIndex == -1)
        return true;
    return false;
}

void Array::appendElement(int element)
{
    if (lastIndex < (capacity - 1))
    {
        ptr[lastIndex + 1] = element;
        lastIndex++;
    }
    else
        cout << "Array is full! ";
}

void Array::insertSpecificElement(int index, int element)
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

void Array::editElement(int index, int element)
{
    if (index > lastIndex)
        cout << "Element can't edit, enter valid contiguous index";
    else
    {
        ptr[index] = element;
        cout << "Element updation successfull";
    }
}

void Array::deleteElement(int index, int element)
{
    int j;
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
            ptr[i] = j;
            ptr[i] = ptr[i + 1];
            ptr[i + 1] = j;
        }
        lastIndex--;
    }
}

bool Array::checkArray_isFullorNot()
{
    if (lastIndex == (capacity - 1))
        return true;
    else
        return false;
}

int Array::getElemnt(int index)
{
    if (lastIndex == -1)
        return 0;
    else if (index > lastIndex)
        return -1;
    else
        return ptr[index];
}

int Array::countElements()
{
    return (lastIndex + 1);
}

int Array::findElement(int element)
{
    for (int i = 0; i <= lastIndex; i++)
    {
        if (ptr[i] == element)
            return i;
    }

    return -1;
}

void Array::displayArray()
{
    for (int i = 0; i <= lastIndex; i++)
        cout << ptr[i] << " ";
}

void Array::sortArray()
{
    if (lastIndex == -1)
        cout << "Array is not initialized!";
    else
    {
        int i, j, k, temp, min;
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

int Array::findGreatestElement()
{
    if (lastIndex == -1)
        cout << "Array is not initialized!";
    else
    {
        int j, k, max;
        max = ptr[0];
        for (j = 1; j <= lastIndex; j++)
        {
            if (ptr[j] > max)
                max = ptr[j];
        }
        return max;
    }
}

int Array::findSmallestElement()
{
    if (lastIndex == -1)
        cout << "Array is not initialized!";
    else
    {
        int j, k, min;
        min = ptr[0];
        for (j = 1; j <= lastIndex; j++)
        {
            if (ptr[j] < min)
                min = ptr[j];
        }
        return min;
    }
}

void Array::searchElement(int element)
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

int Array::calculateSum()
{
    if (lastIndex == -1)
        cout << "Array is not initialized!";
    else
    {
        int sum = 0;
        for (int i = 0; i <= lastIndex; i++)
            sum = sum + ptr[i];

        return sum;
    }
}

float Array::calcuateAverage()
{
    if (lastIndex == -1)
        cout << "Array is not initialized!";
    else
    {
        int sum = 0;
        float average;
        for (int i = 0; i <= lastIndex; i++)
            sum = sum + ptr[i];

        average = sum / lastIndex + 1;
        return average;
    }
}

void Array::rotateArray(char direction, int position)
{
    if (lastIndex == -1)
        cout << "Array is not initialized!";
    else
    {
        if (direction == 'l')
        {
            int k;
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
            int k;
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

void Array::removeDuplicateElements()
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

int Array::secondLargesElement()
{
    if (lastIndex == -1)
        cout << "Array is not initialized!";
    else
    {
        int k, temp1, temp2, maxTemp, max, min;
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

void Array::swapElements(int index1, int index2)
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
        int i;
        i = ptr[index1];
        ptr[index1] = ptr[index2];
        ptr[index2] = i;
        cout << "Elements swaped.";
    }
}

int menu()
{
    int choice;
    cout << endl<< endl<< "1.Check array is empty or not" << endl;
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
    Array array(size);

    while (true)
    {
        switch (menu())
        {
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
            int indx, Elmnt;
            cout << "Enter index(0 to " << size - 1 << ")-> ";
            cin >> indx;
            cout << "Entet element: ";
            cin >> Elmnt;

            array.insertSpecificElement(indx, Elmnt);
            break;

        case 4:
            int index, Element;
            cout << "Enter index(0 to " << size - 1 << ")-> ";
            cin >> index;
            cout << "Entet element: ";
            cin >> Element;

            array.editElement(index, Element);
            break;

        case 5:
            int ind, Elmt;
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
            if (i == -1)
                cout << "Given index has garbage value";
            else if (i == 0)
                cout << "Array is not initialized!";
            else
                cout << i;
            break;

        case 8:
            cout << array.countElements();
            break;

        case 9:
            int I, ELEMENT;
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