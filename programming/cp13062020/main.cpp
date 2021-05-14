#include<bits/stdc++.h>
using namespace std;
#define gc getchar_unlocked
#define fo(i,n) for(ll i=0;i<n;i++)
#define Fo(i,k,n) for(i=k;k<n?i<n:i>n;k<n?i+=1:i-=1)
#define ll long long
#define si(x)	cin>>x
#define sl(x)	cin>>x
#define ss(s)	scanf("%s",s)
#define pi(x)	printf("%d\n",x)
#define pl(x)	printf("%lld\n",x)
#define ps(s)	printf("%s\n",s)
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define clr(x) memset(x, 0, sizeof(x))
#define sortall(x) sort(all(x))
#define tr(it, a) for(auto it = a.begin(); it != a.end(); it++)
#define PI 3.1415926535897932384626
typedef pair<int, int>	pii;
typedef pair<ll, ll>	pl;
typedef vector<int>		vi;
typedef vector<ll>		vl;
typedef vector<pii>		vpii;
typedef vector<pl>		vpl;
typedef vector<vi>		vvi;
typedef vector<vl>		vvl;
int mpow(int base, int exp);
void ipgraph(int m);
void dfs(int u, int par,vector<ll> v,vector<ll> vis);
const int mod = 1000000007;
const int N = 3e5, M = N;
//=======================

vi g[N];
int a[N];
ll ans=0;
ll m;
int solve(){
ll n;
cin>>n>>m;
vector<ll> v,vis;
vector<vector<ll>> tree(n);
fo(i,n){
ll a;
cin>>a;
v.push_back(a);
vis.push_back(0);
}
fo(i,n-1){
ll a,b;
cin>>a>>b;

tree[a].push_back(b);
tree[b].push_back(a);
}
dfs(1,-1,v,vis);
cout<<ans;
}
int main() {
    ios_base::sync_with_stdio(0);
    int t, i, j, k, p, q, r, x, y, u, v, n=1, m;
  //  sl(n);
    fo(i,n){
    solve();
    }
    return 0;
}

int mpow(int base, int exp) {
  base %= mod;
  int result = 1;
  while (exp > 0) {
    if (exp & 1) result = ((ll)result * base) % mod;
    base = ((ll)base * base) % mod;
    exp >>= 1;
  }
  return result;
}

void ipgraph(int n, int m){
	int i, u, v;
	while(m--){
		cin>>u>>v;
		g[u-1].pb(v-1);
		g[v-1].pb(u-1);
	}
}
ll countt=0;
void dfs(int u, int par,vector<ll> v,vector<ll> vis){
	for(int vv:g[u]){
            if(!vis[vv]){
                    vis[vv]=1;
                if (vv == par) continue;
		if(v[vv]){
            countt+=1;
		}
		if(countt==m){
            ans++;
            countt=0;
            return;
		}
		dfs(vv,u,v,vis);

            }
			}
}
int sgn(ll n){
    if(n>0){
        return 1;
    }
    else{
        return -1;
    }
}
ll max_digit(ll n){
    ll lar=0;
while(n){
    ll r=n%10;
    lar=max(r,lar);
    n=n/10;
}
return lar;
}
ll min_digit(ll n){
    ll lar=9;
while(n){
    ll r=n%10;
    lar=min(r,lar);
    n=n/10;
}
return lar;
}
int prime(ll n){
for(ll i=2;i<n;i++){
    if(n%i==0){
   return 0;
    }
}
    return 1;
}

