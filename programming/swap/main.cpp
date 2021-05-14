#include <iostream>

using namespace std;
int swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
    cout<<"In swap function a="<<*a<<" "<<"b="<<*b<<endl;
}
int swap1(int &a,int &b){
    int temp=a;
    a=b;
    b=temp;
    cout<<"In swap function a="<<a<<" "<<"b="<<b<<endl;
}
int main()
{
    int a=3,b=5;
    //swap(&a,&b);//call by address
    swap1(a,b);//call by reference
    cout<<"In main() a="<<a<<" "<<"b="<<b<<endl;
    return 0;
}
