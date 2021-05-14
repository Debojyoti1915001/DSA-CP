#include <bits/stdc++.h>
using namespace std;
#define l long long int
int main(){
   l t;
   cin>>t;
   while(t--){
   l o=0,e=0;
   l n,x;
   cin>>n>>x;
   for(l i=0;i<n;i++){
    l a;cin>>a;
    if(a%2==0){
        ++e;
    }
    else{
        ++o;
    }
   }
   if(x==n){
    if(o%2){
        cout<<"Yes"<<endl;
        continue;
    }
    else{
        cout<<"No"<<endl;
        continue;
    }
   }
   if(o==0){
    cout<<"No"<<endl;
    continue;
   }
   if(e==0){
    if(x%2==0){
        cout<<" No"<<endl;
        continue;
    }
    else{
        cout<<"Yes"<<endl;
        continue;
    }
   }
   else{

    cout<<"Yes"<<endl;

   }


   }
    }


