#include <iostream>
using namespace std;
class Student
{
private:
    int rollNum;
    string name;
    string stream;
    int year;

public:
    Student() : rollNum(0), name("Unnamed"), stream("Unnamed"), year(0) {}

    void inputStudent(int rollNum, string name, string stream, int year)
    {
        this->rollNum = rollNum;
        this->name = name;
        this->stream = stream;
        this->year = year;
    }

    int getRollNum() { return rollNum; }
    string getName() { return name; }
    string getStream() { return stream; }
    int getYear() { return year; }

    void displayStudent()
    {
        cout <<rollNum << " " << name << " " << stream << " " << year << endl;
    }
};

struct node
{
    Student student;
    node *next;
};

class HashTable
{
private:
    int capacity;
    node **table;
public:
    HashTable() : capacity(0), table(nullptr) {}

    HashTable(int capacity)
    {
        this->capacity = capacity;
        table = new node*[capacity];
        for(int i=0; i<capacity; i++)
            table[i] = nullptr;
    }

    void createHashTable(int capacity)
    {
        if (table != nullptr)
            table = nullptr;

        this->capacity = capacity;
        table = new node*[capacity];
        for(int i=0; i<capacity; i++)
            table[i] = nullptr;
    }

    int hashFuction(int rollNum)
    {
        while (rollNum > capacity)
            rollNum = rollNum / capacity;

        return rollNum;
    }

    void insertTable(int RollNum, string name, string stream, int year)
    {
        int index = hashFuction(RollNum);

        node *newNode = new node;
        newNode->student.inputStudent(RollNum, name, stream, year);
        newNode->next = nullptr;

        if(table[index]==nullptr)
            table[index] = newNode;
        else
        {
            node *temp = table[index];
            while (temp->next)
                temp = temp->next;

            temp->next = newNode;            
        }
    }

Student* searchStudent(int RollNum)
{
    int index = hashFuction(RollNum);

    node *temp = table[index];
    while (temp)
    {
        if(temp->student.getRollNum()==RollNum)
            return &temp->student;
        temp = temp->next;
    }
    
    return nullptr;
}

    void displayTable()
    {
        for (int i = 0; i < capacity; i++)
        {
            table[i]->student.displayStudent();
            node *temp = table[i]->next;

            while (temp)
            {
                temp->student.displayStudent();
                temp = temp->next;
            }
        }
    }
};

int main()
{
    HashTable table(5);

    table.insertTable(0, "Amitesh", "BCA", 2024);
    table.insertTable(1, "Rajan", "B TECH", 2024);
    table.insertTable(2, "Ankur", "B TECH", 2024);
    table.insertTable(3, "Dheeraj", "BSC", 2024);
    table.insertTable(4, "Shiva", "BBA", 2024);
    table.insertTable(6, "Shivam", "BBA", 2024);
    table.insertTable(7, "Amitesh", "BCA", 2024);
    table.insertTable(8, "Rajan", "B TECH", 2024);
    table.insertTable(9, "Ankur", "B TECH", 2024);
    table.insertTable(10, "Dheeraj", "BSC", 2024);
    table.insertTable(11, "Shiva", "BBA", 2024);
    table.insertTable(12, "Shivam", "BBA", 2024);
    table.displayTable();

    Student* std = table.searchStudent(19);
    if(std == nullptr)
        cout<<"Student not found";
    else
        std->displayStudent();

    return 0;
}