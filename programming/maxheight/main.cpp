#include<bits/stdc++.h>
using namespace std;
int n,k=0;
string s,z;
map<string,int>m;
string l(string s){
for(int j=0;j<=s.size();j++){
    s[j]=tolower(s[j]);
}
return s;
}
int main(){
cin>>n;
for(int i=0;i<n;i++){
    string a,b,c;
    cin>>a>>b>>c;
    a=l(a);
    c=l(c);
    m[s]=m[z]+1;
    k=max(k,m[s]);
}
cout<<k+1;

}
