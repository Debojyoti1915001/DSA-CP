#include <iostream>
using namespace std;

class Employee
{
    int id;
    //can't pass count from one object to another
    static int count;

public:
    void setData(void)
    {
        cout << "Enter the id" << endl;
        cin >> id;
        count++;
    }
    void getData(void)
    {
        cout << "The id of this employee is " << id << " and this is employee number " << count << endl;
    }

    static void getCount(void){
        // cout<<id; // throws an error
        cout<<"The value of count is "<<count<<endl;
    }
};

// Count is the static data member of class Employee
int Employee::count=1000; // Default value is 0

int main()
{
    Employee azad, arka, debo;
    // harry.id = 1;
    // harry.count=1; // cannot do this as id and count are private

    azad.setData();
    azad.getData();
    //no ref from any object
    Employee::getCount();

    arka.setData();
    arka.getData();
    Employee::getCount();

    debo.setData();
    debo.getData();
    Employee::getCount();

    return 0;
}
