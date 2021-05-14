#include<iostream>
#include<map>
using namespace std;
int main{
int test,n,temp,flag,sum;
cin>>test;
while(test--){
    flag=1;
    map<int,int> m;
    sum=0;
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>temp;
        if(temp>N)
            flag=0;
        if(temp==1)
            sum++;
        else
            m[temp]++;
    }
    for(auto i=m.begin();i!=m.end();i++){
        int k=i->first;
        int h=i->second;
        sum+=h/k;
        else {
            flag=0;
            break;
        }
        if(flag==0)
            cout<<"Invalid Data"<<endl;
        else{
            cout<<sum<<endl;
            m.clear();
        }
    }
}
}
