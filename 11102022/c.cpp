// Debojyoti Das
//NIT Silchar
#include <bits/stdc++.h>
using namespace std;
#define l long long int

void solve()
{
    long long n,sum=0,ans,now=0,k,ans1,flag;
		cin>>n;
		ans=n;
        vector<l>a(n+1);
		for(int i=1;i<=n;i++) cin>>a[i];
		for(int i=1;i<=n;i++){
			sum+=a[i],now=0,k=i+1,ans1=i,flag=0;
			for(int j=i+1;j<=n;j++){
				now+=a[j];
				if(now==sum){
					flag=1;
					now=0;
					ans1=max(ans1,j-k+1);
					k=j+1;
				}
			}
			if(k!=n+1) ans1=n;
			ans=min(ans1,ans);
		}
		cout<<ans<<endl;
}
 
int main()
{
    int t = 1;
    cin >> t;
    for (l i = 1; i <= t; i++)
    {
        //            cout<<"Case #"<<i<<": ";
        solve();
    }
    return 0;
}
 