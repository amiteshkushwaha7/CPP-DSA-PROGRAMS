#include <iostream>
using namespace std;
class Employee
{
private:
    int emp_id;
    string name;
    float salary;

public:
    void addEmployee(int emp_id, string name, float salary)
    {
        this->emp_id = emp_id;
        this->name = name;
        this->salary = salary;
    }

    void setEmpId(int emp_id) { this->emp_id = emp_id; }
    void setName(string name) { this->name = name; }
    void setSalary(float salary) { this->salary = salary; }

    int getEmpId() { return emp_id; }
    string getName() { return name; }
    float getSalary() { return salary; }

    void displayEmployee();

    
    void selectionSort(Employee*, int);
    void selectionSortString(Employee*, int);

    void bubbleSort(Employee*, int);
    void bubbleSortString(Employee*, int);

    void modifiedBubbleSort(Employee*, int);
    void modifiedBubbleSortString(Employee*, int);

    
    void insertionSort(Employee*, int);
    void insertionSortString(Employee*, int);

    void splitArray(Employee*,int);
    Employee* mergeSort(Employee[],int, Employee[],int);

    void splitArrayString(Employee*,int);
    Employee* mergeSortString(Employee[],int, Employee[],int);

    int partation(Employee[],int,int);
    void quickSort(Employee*,int,int);

    int partationString(Employee[],int,int);
    void quickSortString(Employee*,int,int);
};

void Employee::displayEmployee()
{
    cout<<"Employee"<<": ";
    cout<<getEmpId()<<" " <<getName()<<" " <<getSalary() <<endl;
}

void Employee::bubbleSort(Employee *emp, int size)
{
    Employee temp;
    for(int i=1; i<size-1; i++)
    {
        for(int j=0; j<size-i; j++)
        {
            if(emp[j].getEmpId() > emp[j+1].getEmpId())
            {
                temp = emp[j];
                emp[j] = emp[j+1];
                emp[j+1] = temp;
            }
        }
    }
}

void Employee::bubbleSortString(Employee *emp, int size)
{
    Employee temp;

    for(int i=1; i<size-1; i++)
    {
        for(int j=0; j<size-i; j++)
        {
            if(emp[j].getName() > emp[j+1].getName())
            {
                temp = emp[j];
                emp[j] = emp[j+1];
                emp[j+1] = temp;
            }
        }
    }
}

void Employee::modifiedBubbleSort(Employee *emp, int size)
{
    Employee temp;
    bool flag = false;

    for(int i=1; i<size-1; i++)
    {
        for(int j=0; j<size-i; j++)
        {
            if(emp[j].getEmpId() > emp[j+1].getEmpId())
            {
                temp = emp[j];
                emp[j] = emp[j+1];
                emp[j+1] = temp;

                flag = true;
            }
        }
        if(flag == false)
            break;
    }
}

void Employee::modifiedBubbleSortString(Employee *emp, int size)
{
    Employee temp;
    bool flag = false;

    for(int i=1; i<size-1; i++)
    {
        for(int j=0; j<size-i; j++)
        {
            if(emp[j].getName() > emp[j+1].getName())
            {
                temp = emp[j];
                emp[j] = emp[j+1];
                emp[j+1] = temp;

                flag = true;
            }
        }
        if(flag == false)
            break;
    }
}

void Employee::selectionSort(Employee *emp, int size)
{
    int minIndex;
    Employee temp;

    for(int i=0; i<size; i++)
    {
        minIndex = i;
        for(int j=i+1; j<size; j++)
        {
            if(emp[minIndex].getEmpId() > emp[j].getEmpId())
                minIndex = j;
        }
        
        temp = emp[i];
        emp[i] = emp[minIndex];
        emp[minIndex] = temp;
    }
}

void Employee::selectionSortString(Employee *emp, int size)
{
    int minIndex;
    Employee temp;

    for(int i=0; i<size-1; i++)
    {
        minIndex = i;
        for(int j=i+1; j<size; j++)
        {
            if(emp[minIndex].getName() > emp[j].getName())
                minIndex = j;
        }
        
        temp = emp[i];
        emp[i] = emp[minIndex];
        emp[minIndex] = temp;
    }
}

void Employee::splitArray(Employee *emp, int size)
{
    int size1 = size/2;
    int size2 = size - size1;

    Employee arr1[size1];
    Employee arr2[size2];

    for(int i=0; i<size1; i++)
        arr1[i] = emp[i];

    for(int i=size1,j=0; i<size; i++,j++)
        arr2[j] = emp[i];

    if(size1/2 >0) 
        splitArray(arr1, size1);
    
    if(size2/2 > 0)
        splitArray(arr2, size2);

    Employee *sortArray = mergeSort(arr1,size1, arr2,size2);

    for(int i=0; i<size; i++)
        emp[i] = sortArray[i];

    delete []sortArray;
    sortArray = nullptr;
}

Employee* Employee::mergeSort(Employee arr1[],int size1, Employee arr2[], int size2)
{
    int i=0,j=0,k=0;
    Employee *arr3 = new Employee[size1+size2];

    while (i<size1 && j<size2)
    {
        if(arr1[i].getEmpId() < arr2[j].getEmpId())
        {
            arr3[k] = arr1[i];
            i++;
            k++;
        }
        else if(arr1[i].getEmpId() > arr2[j].getEmpId())
        {
            arr3[k] = arr2[j];
            j++;
            k++;
        }
        else
        {
            arr3[k] = arr1[i];
            arr3[k+1] = arr2[j];

            k = k+2;
            i++;
            j++;
        }
    }
    
    while (i<size1)
    {
        arr3[k] = arr1[i];
        k++;
        i++;
    }

    while (j<size2)
    {
        arr3[k] = arr2[j];
        j++;
        k++;
    }
    
    return arr3;
}

void Employee::splitArrayString(Employee *emp, int size)
{
    int size1 = size/2;
    int size2 = size - size1;

    Employee arr1[size1];
    Employee arr2[size2];

    for(int i=0; i<size1; i++)
        arr1[i] = emp[i];

    for(int i=size1,j=0; i<size; i++,j++)
        arr2[j] = emp[i];

    if(size1/2 >0) 
        splitArray(arr1, size1);
    
    if(size2/2 > 0)
        splitArray(arr2, size2);

    Employee *sortArray = mergeSortString(arr1,size1, arr2,size2);

    for(int i=0; i<size; i++)
        emp[i] = sortArray[i];

    delete []sortArray;
    sortArray = nullptr;
}

Employee* Employee::mergeSortString(Employee arr1[],int size1, Employee arr2[], int size2)
{
    int i=0,j=0,k=0;
    Employee *arr3 = new Employee[size1+size2];

    while (i<size1 && j<size2)
    {
        if(arr1[i].getName() < arr2[j].getName())
        {
            arr3[k] = arr1[i];
            i++;
            k++;
        }
        else if(arr1[i].getName() > arr2[j].getName())
        {
            arr3[k] = arr2[j];
            j++;
            k++;
        }
        else
        {
            arr3[k] = arr1[i];
            arr3[k+1] = arr2[j];

            k = k+2;
            i++;
            j++;
        }
    }
    
    while (i<size1)
    {
        arr3[k] = arr1[i];
        k++;
        i++;
    }

    while (j<size2)
    {
        arr3[k] = arr2[j];
        j++;
        k++;
    }
    
    return arr3;
}

void Employee::insertionSort(Employee *emp, int size)
{
    Employee temp;
    bool flag = false;
    int i,j;

    for(i=0; i<size-1; i++)
    {
        temp = emp[i+1];
        for(j=i; j>=0; j--)
        {
            if(temp.getEmpId() < emp[j].getEmpId())
            {
                emp[j+1] = emp[j];
                flag = true;
            }
            else
            {
                emp[j+1] = temp;
                break;
            }
        }

        if(flag == true)
            emp[j+1] = temp;
    }
}

void Employee::insertionSortString(Employee *emp, int size)
{
    Employee temp;
    bool flag = false;
    int i,j;

    for(i=0; i<size-1; i++)
    {
        temp = emp[i+1];
        for(j=i; j>=0; j--)
        {
            if(temp.getName() < emp[j].getName())
            {
                emp[j+1] = emp[j];
                flag = true;
            }
            else
            {
                emp[j+1] = temp;
                break;
            }
        }

        if(flag == true)
            emp[j+1] = temp;
    }
}

int Employee::partation(Employee array[], int left, int right)
{
    int cnt = 0, pvot = left;
    Employee k;

    for (int i = left + 1; i <= right; i++)
    {
        if (array[pvot].getEmpId() > array[i].getEmpId())
            cnt++;
    }

    k = array[pvot + cnt];
    array[pvot + cnt] = array[pvot];
    array[pvot] = k;
    pvot = pvot + cnt;

    while (left != right)
    {
        while (array[left].getEmpId() < array[pvot].getEmpId())
            left++;

        while (array[right].getEmpId() > array[pvot].getEmpId())
            right--;

        if ((array[left].getEmpId() > array[pvot].getEmpId()) && (array[right].getEmpId() < array[pvot].getEmpId()))
        {
            k = array[left];
            array[left] = array[right];
            array[right] = k;
        }
    }

    return pvot;
}

void Employee::quickSort(Employee *emp, int left, int right)
{
    if (left >= right)
        return;
    
    int pvot = partation(emp, left, right);

    quickSort(emp, left, pvot - 1);
    quickSort(emp, pvot + 1, right);
}

int Employee::partationString(Employee array[], int left, int right)
{
    int cnt = 0, pvot = left;
    Employee k;

    for (int i = left + 1; i <= right; i++)
    {
        if (array[pvot].getName() > array[i].getName())
            cnt++;
    }

    k = array[pvot + cnt];
    array[pvot + cnt] = array[pvot];
    array[pvot] = k;
    pvot = pvot + cnt;

    while (left != right)
    {
        while (array[left].getName() < array[pvot].getName())
            left++;

        while (array[right].getName() > array[pvot].getName())
            right--;

        if ((array[left].getName() > array[pvot].getName()) && (array[right].getName() < array[pvot].getName()))
        {
            k = array[left];
            array[left] = array[right];
            array[right] = k;
        }
    }

    return pvot;
}

void Employee::quickSortString(Employee *emp, int left, int right)
{
    if (left >= right)
        return;
    
    int pvot = partation(emp, left, right);

    quickSort(emp, left, pvot - 1);
    quickSort(emp, pvot + 1, right);
}

int main()
{
    Employee emp[5];
    emp[0].addEmployee(3, "rajan", 30);
    emp[1].addEmployee(2, "ankur", 20);
    emp[2].addEmployee(1, "amitesh", 10);
    emp[3].addEmployee(5, "shiva", 50);
    emp[4].addEmployee(4, "dheeraj", 40);
 
 
    emp[0].selectionSort(emp, 5);
    emp[0].selectionSortString(emp, 5);

    emp[0].bubbleSort(emp, 5);
    emp[0].bubbleSortString(emp, 5);

    emp[0].modifiedBubbleSort(emp, 5);
    emp[0].modifiedBubbleSortString(emp, 5);

    emp[0].splitArray(emp, 5);
    emp[0].splitArrayString(emp, 5);

    emp[0].insertionSort(emp, 5);
    emp[0].insertionSortString(emp, 5);

    emp[0].quickSort(emp, 0, 5);
    emp[0].quickSortString(emp, 0, 5);
    
    for(int i=0; i<5; i++)
        emp[i].displayEmployee();

    return 0;
}