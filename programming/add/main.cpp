#include <iostream>
using namespace std;
int add(int c,int d);
int main()
{
    int a,b;
    a=1,b=2;
    add(a,b);
    return 0;
}
int add(int c,int d){
 cout<<c+d;
}
