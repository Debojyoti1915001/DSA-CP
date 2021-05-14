#include <bits/stdc++.h>

using namespace std;
#define l long long int
int main()
{
    l n,m;
    cin>>n>>m;
    l a[n],b[m];
    for(l i=0;i<n;i++){
        cin>>a[i];
    }
    for(l i=0;i<m;i++){
        cin>>b[i];
    }
    cout<<"Intersection"<<endl;
    l i=0,j=0;
    while(i<n&&j<m){
        if(a[i]>b[j])j++;
        else if(a[i]<b[j])i++;
        else{
            cout<<a[i]<<" ";
            i++;j++;
        }
    }
    cout<<"\nUnion"<<endl;
    i=0,j=0;
    while(i<n&&j<m){
        if(a[i]>b[j]){
            cout<<b[j]<<" ";
            j++;
        }
        else if(a[i]<b[j]){
            cout<<a[i]<<" ";
            i++;
        }
        else if(a[i]==b[j]){
            cout<<a[i]<<" ";
            i++;j++;
        }

    }
     while(i<n){
            cout<<a[i]<<" ";
            i++;
        }
        while(j<m){
        cout<<b[j]<<" ";
        j++;
        }
    return 0;
}
