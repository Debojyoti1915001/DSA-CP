#include <bits/stdc++.h>
using namespace std;
long long s,i,j,n,m,x,a[109],b[109];
int main(){
cin>>n>>m;
for(i=1;i<=n;i++)
{cin>>a[i]; s+=a[i];}
for(i=0;i<m;i++) 
{cin>>x; s-=a[x]; b[i]=a[x];}
sort(b,b+m,greater<long long>());
if(s>b[0]) s*=2;
else s+=b[0];
for(i=1;i<m;i++)
s*=2;
cout<<s;
return 0;
}