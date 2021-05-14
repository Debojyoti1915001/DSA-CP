#include <bits/stdc++.h>
#define l long long int
using namespace std;
#define R 100
#define C 100

void spiralPrint(l m,l n,l ar[R][C]){
    l k=0,ll=0;
    //m :no of rows
    //n :no of columns
    while(k<m&&ll<n){
        for(l i=ll;i<n;++i){
            cout<<ar[k][i]<<" ";
        }k++;
        for(l i=k;i<m;++i){
            cout<<ar[i][n-1]<<" ";
        }
        n--;
        if(k<m){
            for(l i=n-1;i>=ll;--i){
                cout<<ar[m-1][i]<<" ";
            }
            m--;
        }
        if(ll<n){
            for(l i=m-1;i>=k;--i){
                cout<<ar[i][ll]<<" ";
            }
            ll++;
        }
    }
}
int main()
{
    l ar[R][C];
    l n,m;
    cin>>n>>m;
    for(l i=0;i<n;i++){
        for(l j=0;j<m;j++){
            cin>>ar[i][j];
        }
    }
    spiralPrint(n,m,ar);
    return 0;
}
