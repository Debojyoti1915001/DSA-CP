#include <iostream>
using namespace std;
int sum(int a,int b){//formal parametes
    cout<<a+b<<endl;
}
int main()
{
    int a,b;
    cout<<"Enter two values to add:\n";
    cin>>a>>b;
    sum(a,b);//actual parameters
    return 0;
}
