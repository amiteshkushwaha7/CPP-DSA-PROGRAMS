#include<iostream>
#include<array>
using namespace std;
class Complex
{
    public:
        int x;
        int y;
    
        Complex():x(0),y(0){}

        Complex(int x,int y)
        {
            this->x = x;
            this->y = y;
        }

        Complex operator+(Complex &other)
        {
            Complex C;
            C.x = x + other.x;
            C.y = y + other.y;

            return C;
        }

        ~Complex(){};
};

void insertComplex(array <Complex,5>&arr)
{
    for (int i = 0; i < 5; i++)
    {
        cout<<"Enter Complex"<<i+1<<": ";
        cin>>arr[i].x >>arr[i].y;
    }
}

void displayComplex(array <Complex,5>&arr)
{
    for(Complex C : arr)
        cout<<C.x<<"+"<<C.y<<"i"<<endl;
    
}

Complex sumComplex(array <Complex,5>&arr)
{
    Complex sum;
    for(Complex C : arr)
        sum = sum + C;
    return sum;
}

int main()
{
    array <Complex,5>A;
    
    insertComplex(A);
    displayComplex(A);
    Complex sum = sumComplex(A);
    cout<<sum.x<<"+"<<sum.y<<"i"<<endl;

    return 0;
}
