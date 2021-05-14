#include <bits/stdc++.h>
using namespace std;
#define l long long int
int main()
{
    l n;
    cin>>n;
    l ar[n];
    for(l i=0;i<n;i++){
        cin>>ar[i];
    }
    for(l i=0;i<n/2;i++){
        l temp=ar[i];
        ar[i]=ar[n-i-1];
        ar[n-i-1]=temp;
    }
    for(l i=0;i<n;i++)cout<<ar[i]<<" ";
    return 0;
}
