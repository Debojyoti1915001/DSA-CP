#include <iostream>
using namespace std;

class Complex
{
    int a, b;
    static int c;
public:
    // Creating a Constructor
    // Constructor is a special member function with the same name as of the class.
    //It is used to initialize the objects of its class
    //It is automatically invoked whenever an object is created
    //declared in public section
    Complex(void); // Constructor declaration

    void printNumber()
    {
        cout << "Your number is " << a << " + " << b << "i" << endl;
    }
};
int Complex::c=0;
Complex ::Complex(void) // ----> This is a default constructor as it takes no parameters
{
    if(c==0){
    a = 10;
    b = 0;
    c++;
    }else{
        a = 1;
        b = 5;
        c--;
    } 
    // cout<<"Hello world";
}
int main()
{
    Complex c1, c2, c3;
    c1.printNumber();
    c2.printNumber();
    c3.printNumber();

    return 0;
}
