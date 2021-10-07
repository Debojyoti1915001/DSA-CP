#include <iostream>
using namespace std;
//   Virtual base classes offer a way to save space and avoid ambiguities in class hierarchies that use multiple inheritances. When a base class is specified as a virtual base, it can act as an indirect base more than once without duplication of its data members. A single copy of its data members is shared by all the base classes that use virtual base.
class A {
public:
    void show()
    {
        cout << "Hello form A \n";
    }
};
  
class B : public virtual A {
};
  
class C : public virtual A {
};
  
class D : public B, public C {
};
  
int main()
{
    D object;
    object.show();
}
// Example 1


// #include <iostream>
// using namespace std;
  
// class A {
// public:
//     int a;
//     A() // constructor
//     {
//         a = 10;
//     }
// };
  
// class B : public virtual A {
// };
  
// class C : public virtual A {
// };
  
// class D : public B, public C {
// };
  
// int main()
// {
//     D object; // object creation of class d
//     cout << "a = " << object.a << endl;
  
//     return 0;
// }
// Output:
// a = 10
// Explanation :The class A has just one data member a which is public. This class is virtually inherited in 
// class B and class C. Now class B and class C becomes virtual base class and no duplication of data member a is done.