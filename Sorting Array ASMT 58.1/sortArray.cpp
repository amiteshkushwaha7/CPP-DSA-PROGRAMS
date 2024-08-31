#include <iostream>
using namespace std;
void bubbleSort(int array[], int size)
{
    int k;
    for (int j = 1; j < size - 1; j++)
    {
        for (int i = 0; i < size - j; i++)
        {
            if (array[i] > array[i + 1])
            {
                k = array[i];
                array[i] = array[i + 1];
                array[i + 1] = k;
            }
        }
    }
}

void modifiedBubbleSort(int array[], int size)
{
    int k;
    for (int j = 1; j < size - 1; j++)
    {
        bool b = false;
        for (int i = 0; i < size - j; i++)
        {
            if (array[i] > array[i + 1])
            {
                k = array[i];
                array[i] = array[i + 1];
                array[i + 1] = k;
                b = true;
            }
        }
        if (b == false)
            break;
    }
}

void insertionSort(int array[], int size)
{
    int min, i, j, k;
    bool b = false;
    for (i = 0; i < size - 1; i++)
    {
        min = array[i + 1];
        for (j = i; j >= 0; j--)
        {
            if (min < array[j])
            {
                array[j + 1] = array[j];
                b = true;
            }
            else
            {
                array[j + 1] = min;
                break;
            }
        }
        if (b == true)
            array[j + 1] = min;
    }
}

void selectionSort(int array[], int size)
{
    int k, min, temp;
    for (int i = 0; i < size; i++)
    {
        min = array[i];
        temp = i;
        for (int j = i + 1; j < size; j++)
        {
            if (min > array[j])
            {
                min = array[j];
                temp = j;
            }
        }

        k = array[i];
        array[i] = min;
        array[temp] = k;
    }
}

int partation(int array[], int left, int right)
{
    int k, cnt = 0, pvot = left;
    for (int i = left + 1; i <= right; i++)
    {
        if (array[pvot] > array[i])
            cnt++;
    }

    k = array[pvot + cnt];
    array[pvot + cnt] = array[pvot];
    array[pvot] = k;
    pvot = pvot + cnt;

    while (left != right)
    {
        while (array[left] < array[pvot])
            left++;

        while (array[right] > array[pvot])
            right--;

        if ((array[left] > array[pvot]) && (array[right] < array[pvot]))
        {
            k = array[left];
            array[left] = array[right];
            array[right] = k;
        }
    }

    return pvot;
}

void quickSort(int array[], int left, int right)
{
    if (left >= right)
        return;
    
    int pvot = partation(array, left, right);

    quickSort(array, left, pvot - 1);
    quickSort(array, pvot + 1, right);
}

int *mergeSort(int arr1[], int size1, int arr2[], int size2)
{
    int i = 0, j = 0, k = 0;
    int *arr3 = new int[size1 + size2];
    while (i < size1 && j < size2)
    {
        if (arr1[i] < arr2[j])
        {
            arr3[k] = arr1[i];
            k++;
            i++;
        }
        else if (arr1[i] > arr2[j])
        {
            arr3[k] = arr2[j];
            k++;
            j++;
        }
        else
        {
            arr3[k] = arr1[i];
            arr3[k + 1] = arr2[j];
            k = k + 2;
            i++;
            j++;
        }
    }

    while (j < size2)
    {
        arr3[k] = arr2[j];
        j++;
        k++;
    }
    while (i < size1)
    {
        arr3[k] = arr1[i];
        i++;
        k++;
    }

    return arr3;
}

void splitArray(int *arr, int size)
{
    int size1 = size / 2;
    int size2 = (size - size1);
    int arr1[size1];
    int arr2[size2];

    for (int i = 0; i < size1; i++)
        arr1[i] = arr[i];

    for (int i = size1, j = 0; i < size; i++, j++)
        arr2[j] = arr[i];

    if (size1 / 2 > 0)
        splitArray(arr1, size1);

    if (size2 / 2 > 0)
        splitArray(arr2, size2);

    int *sortArr = mergeSort(arr1, size1, arr2, size2);

    for (int i = 0; i < size; i++)
        arr[i] = sortArr[i];

    delete[] sortArr;
    sortArr = nullptr;
}

int main()
{
    int array[10] = {40, 21, 68, 38, 70, 25, 90, 18, 7, 54};

    cout<<"Bubble sort: "<<endl;
    bubbleSort(array, 10);
    for (int i = 0; i < 10; i++)
        cout << array[i] << " ";

    cout<<endl<<endl<<"Modified bubble sort: "<<endl;
    modifiedBubbleSort(array, 10);
    for (int i = 0; i < 10; i++)
        cout << array[i] << " ";

    cout<<endl<<endl<<"Insertion sort: "<<endl;
    insertionSort(array, 10);
    for (int i = 0; i < 10; i++)
        cout << array[i] << " ";

    cout<<endl<<endl<<"Selection sort: "<<endl;
    selectionSort(array, 10);
    for (int i = 0; i < 10; i++)
        cout << array[i] << " ";

    cout << endl << endl<< "Quick sort: " << endl;
    quickSort(array, 0, 9);
    for (int i = 0; i < 10; i++)
        cout << array[i] << " ";

    splitArray(array, 10);
    cout << endl<< endl<< "Merge sort: " << endl;
    for (int i = 0; i < 10; i++)
        cout << array[i] << " ";

    return 0;
}
