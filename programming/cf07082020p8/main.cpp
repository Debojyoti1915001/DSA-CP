//1915001 Debojyoti Das NIT Silchar
//Jai Mata Di
//FOR MA and BABA
#include<bits/stdc++.h>
using namespace std;
#define gc getchar_unlocked
#define fo(i,n) for(l i=0;i<n;i++)
#define fr(i,a,b) for(int i=a;i<=b;i++)
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
template<typename T> T gcd(T a,T b) { if(a==0) return b; return gcd(b%a,a); }
template<typename T> T pow(T a,T b, l m){T ans=1; while(b>0){ if(b%2==1) ans=(ans*a)%m; b/=2; a=(a*a)%m; } return ans%m; }

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
void dfs(l u, l par){
	for(int v:g[u]){
		if (v == par) continue;
		dfs(v, u);
	}
}
int per(l n){
if((l)sqrt(n)==(double)sqrt(n)){
    return 1;
}
return 0;
}
int vowel(char c){
if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u'){
    return 1;
}
 return 0;
}
//=======================

void solve(){
l a,b,c,d,e,f;
cin>>a>>b>>c>>d>>e>>f;
l m=-1;
for(l i=0;i<=d;i++){
    l cost=min(a,d-i)*e+min(min(b,c),i)*f;
    m=max(m,cost);
}
cout<<m;
}
int main(){
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        cout<<fixed;
        cout<<setprecision(10);
//        freopen("timber_input.txt", "r", stdin);
//        freopen("timber_output.txt", "w", stdout);
        int t=1;
      //cin>>t;
        for(l i=1;i<=t;i++){
//            cout<<"Case #"<<i<<": ";
            solve();
        }
        return 0;
    }



