#include<bits/stdc++.h>
using namespace std;
#define l long long int
#define N 100001
vector<l> adj[N];
bool odd(l n){
    if((int)sqrt(n)==(double)sqrt(n)){
        return 1;
    }
    return 0;
}
l ans[N];
int dfs(int node,int parent){
    int count=0;
    for(auto i=adj[node].begin();i!=adj[node].end();i++){
        if(*i!=parent){
            count+=dfs(*i,node);
        }
    }
    if(odd(node)){
        count++;
    }
    ans[node]=count;
    return count;
}
int main(){
l n;
cin>>n;
l ini;
for(l i=0;i<n-1;i++){

    l a,b;
    cin>>a>>b;
    if(i==0){
         ini=a;
        }
    adj[a].push_back(b);
    adj[b].push_back(a);
}
dfs(ini,-1);
l test;
cin>>test;
while(test--){
    l a;
    cin>>a;
    cout<<ans[a];
}

}
