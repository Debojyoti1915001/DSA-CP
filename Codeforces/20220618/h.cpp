#include<bits/stdc++.h>
using namespace std;

#define ll long long
const int N=2e5+10;


ll res=0;
int t=0, gp=1;
int n,m;
queue<int> Q[N];
int tin[N], tout[N], mn[N];
bool vis[N], vis2[N], bri[N];
vector<pair<int, int> > g[N];
vector<int> vv[N], ver[N];




void func2(int k)
{
	int comp=gp;
	Q[comp].push(k);
	vis2[k]=1;
	while(!Q[comp].empty())
	{
		int u=Q[comp].front();
		Q[comp].pop();
		ver[comp].push_back(u);
		for(auto it:g[u])
		{
			int v=it.first;
			int edgeidx=it.second;
			if(vis2[v])
				continue;
			if(bri[edgeidx])
			{
				gp++;
				vv[comp].push_back(gp);
				vv[gp].push_back(comp);
				func2(v);
			}
			else
			{
				Q[comp].push(v);
				vis2[v]=1;
			}
		}
	}
}
void func1(int k, int par)
{
	vis[k]=1;
	tin[k]=++t;
	mn[k]=tin[k];
	for(auto it:g[k])
	{
		if(it.first==par)
			continue;
		if(vis[it.first])
		{	
			mn[k]=min(mn[k], tin[it.first]);
			continue;
		}
		func1(it.first, k);
		mn[k]=min(mn[k], mn[it.first]);
		if(mn[it.first]>tin[k])
			bri[it.second]=1;
	}
	tout[k]=t;
}
void  func3(int u, int par){
    ll sz1=ver[u].size();
    for(int v:vv[u]){
        if(v==par)continue;
        ll sz2=ver[v].size();
        res+=sz1*sz2;
        func3(v,u);
    }
}



void solve(){
    cin>>n>>m;
    t=0;gp=1;
    res=0;
    for(int i=0;i<=max(n,m);i++){
        vis[i]=0, vis2[i]=0, bri[i]=0;
        g[i].clear();
        vv[i].clear();
        ver[i].clear();
    }
    for(int i=1;i<=m;i++){
        int u,v;
        cin>>u>>v;
        g[u].push_back({v,i});
        g[v].push_back({u,i});
    }
    func1(1,0);
    func2(1);
    func3(1,0);
    cout<<res<<endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}