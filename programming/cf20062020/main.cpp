#include<bits/stdc++.h>
using namespace std;
#define gc getchar_unlocked
#define fo(i,n) for(l i=0;i<n;i++)
#define Fo(i,k,n) for(i=k;k<n?i<n:i>n;k<n?i+=1:i-=1)
#define l long long int
#define si(x)	cin>>x
#define ss(s)	cin>>s
#define pi(x)	cout<<x<<" "
#define pl(x)	cout<<x<<endl
#define ps(s)	cout<<s
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define pb push_back
#define mp make_pair
#define pf push_front
#define popb pop_back
#define popf pop_front
#define yes cout << "YES\n"
#define no cout << "NO\n"
#define nl cout << endl
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define clr(x) memset(x, 0, sizeof(x))
#define sortall(x) sort(all(x))
#define tr(it, a) for(auto it = a.begin(); it != a.end(); it++)
#define PI 3.1415926535897932384626
typedef pair<int, int>	pii;
typedef pair<l, l>	pl;
typedef vector<int>		vi;
typedef vector<l>		vl;
typedef vector<pii>		vpii;
typedef vector<pl>		vpl;
typedef vector<vi>		vvi;
typedef vector<vl>		vvl;

const l mod = 1000000007;
const l N = 3e5, M = N;
vi g[N];
l a[N];
l mpow(l base,l exp) {
  base %= mod;
  int result = 1;
  while (exp > 0) {
    if (exp & 1) result = ((l)result * base) % mod;
    base = ((l)base * base) % mod;
    exp >>= 1;
  }
  return result;
}

void ipgraph(l n, l m){
	l i, u, v;
	while(m--){
		cin>>u>>v;
		g[u-1].pb(v-1);
		g[v-1].pb(u-1);
	}
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
int prime(l n){
for(l i=2;i<n;i++){
    if(n%i==0){
   return 0;
    }
}
    return 1;
}
 vl v[10005];
 l f=0;
void dfs(l node, l par ,l a,l b){
    if((par==a&&node==b)||(par==b&&node==a)){
            yes;
            f=1;
            return;
		}
	for(int vv:v[node]){
		if (vv == par) continue;
		dfs(vv, node,a,b);
	}
}
//=======================

int main() {
    ios_base::sync_with_stdio(0);
    l test=1;
//    cin>>test;
    while(test--){
    l n;
    cin>>n;
    map<string,string> m,r;
 for(l i=0;i<n;i++){
   string a,b;
   cin>>a>>b;
   if(r.find(a)==r.end()){
    m[a]=b;
    r[b]=a;
   }
   else{
    m[r[a]]=b;
    r[b]=r[a];
   }
     }
    cout<<m.size()<<endl;
    for(auto itr=m.begin();itr!=m.end();itr++){
        cout<<itr->F<<" "<<itr->S<<endl;
    }
    }
    return 0;
}



