#include <iostream>
#define ll long long int
using namespace std;
int swap(ll &a,ll &b){
    ll temp=a;
    a=b;
    b=temp;
}
int main()
{
    ll a,b;
    a=1,b=2;
    swap(a,b);
    cout<<"a="<<a<<" b="<<b<<endl;
    return 0;
}
