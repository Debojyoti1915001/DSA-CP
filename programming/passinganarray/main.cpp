#include <iostream>
#define ll long long int
using namespace std;
int fun(ll ar[],ll n){
ll sum=0;
for(ll i=0;i<n;i++){
    sum+=ar[i];
}
cout<<sum<<endl;
}
int main()
{
    ll n;
    cin>>n;
    ll ar[n];
    for(ll i=0;i<n;i++){
        cin>>ar[i];
    }
    fun(ar,n);
    return 0;
}
