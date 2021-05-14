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
    l j=0;
    for(l i=0;i<n;i++){
        if(ar[i]<0){
            swap(ar[i],ar[j]);
            j++;
        }
    }
    for(l i=0;i<n;i++){
        cout<<ar[i]<<" ";
    }
    return 0;
}
