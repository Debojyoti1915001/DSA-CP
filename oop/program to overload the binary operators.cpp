// Debojyoti Das
//NIT Silchar
#include <bits/stdc++.h>
using namespace std;
class A{
    int x;
    public:
    A(){};
    A(int i){
        x=i;
    }
    void operator+(A);
    void display();
};
void A::operator+(A a){
    int m=x+a.x;
    cout<<"Adding : "<<m;
}
int main()
{
    A a1(5);
    A a2(1000);
    A a3(1000);
    a1+a2;
    return 0;
}
