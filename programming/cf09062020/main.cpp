#include <bits/stdc++.h>
using namespace std;
#define l long long
int prime(l n){
for(l i=2;i<n;i++){
    if(n%i==0){
   return 0;
    }
}
    return 1;
}
int sgn(l n){
    if(n>0){
        return 1;
    }
    else{
        return -1;
    }
}
l max_digit(l n){
    l lar=0;
while(n){
    l r=n%10;
    lar=max(r,lar);
    n=n/10;
}
return lar;
}
l min_digit(l n){
    l lar=9;
while(n){
    l r=n%10;
    lar=min(r,lar);
    n=n/10;
}
return lar;
}
l INF=999999999999;
void solve(){
    l n;l flag=0;
    cin>>n;
    vector<l>v;
    for(l i=0;i<n;i++){
            l a;
        cin>>a;
        v.push_back(a);
    }
    for(l i=0;i<pow(2,n);i++){
        l sum=0,x=0,e=0;
        for(l k=0;k<n;k++){
            if(k&(1<<i)){
                sum=sum+v[k];
                x=x^v[k];
                cout<<x<<endl;
                e++;
            }

        }

        if(sum==2*x){
                cout<<e<<endl;

        for(l k=0;k<n;k++){
            if(k&(1<<i)){
            cout<<v[i]<<" ";
            flag=1;
            }
            }
        }
        if(flag==1){
            break;
        }
        x=0,sum=0;
    }
cout<<endl;
}
void solve1(){
l n;
cin>>n;
l sum=0,x=0;
for(l i=0;i<n;i++){
    l a;
    cin>>a;
   sum=sum+a;
   x=x^a;
}
cout<<2<<endl<<x<<" "<<(sum+x)<<endl;

}
using vi=vector<int>;
using vii=vector<vi>;
void dfs1(const vii&al,vi&ac,int a,int depth){
    ac[depth]++;
    for(int u:al[a])
        dfs1(al,ac,u,depth+1);
}
int main(){
l test=1;
cin>>test;
while(test--){
    l n,f=-1;
    cin>>n;
    vector<l> kings(n);
    for(l i=0;i<n;i++){
        l m,fla=-1;
        cin>>m;
        for(l j=0;j<m;j++){
            l x;
            cin>>x;
            --x;
            if(fla==-1&&!kings[x]){
                kings[x]=1;
                fla=j;
            }
        }
        if(fla==-1){
            f=i;
        }
    }
    if(f==-1){
        cout<<"OPTIMAL\n";
    }
    else{
     cout<<"IMPROVE\n"<<f+1<<" ";
     for(l i=0;i<n;i++){
        if(!kings[i]){
            cout<<i+1<<endl;
            break;
        }
     }
    }
}
}
