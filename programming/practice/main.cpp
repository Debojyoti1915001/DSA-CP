#include<bits/stdc++.h>
using namespace std;
stack<int> s;
int insert_bottom(int x){
    if(s.size()==0){
        s.push(x);
    }
    else{
        int a;
        a=s.top();
        s.pop();
        insert_bottom(a);
        s.push(x);
    }
}
int reverse(){
 if(s.size()>0){
    int a=s.top();
    s.pop();
    reverse();
    insert_bottom(a);
 }
}
int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        s.push(a);
    }
    reverse();
    for(int i=0;i<n;i++){
        int a=s.top();
        cout<<a<<" ";
        s.pop();
    }
}
