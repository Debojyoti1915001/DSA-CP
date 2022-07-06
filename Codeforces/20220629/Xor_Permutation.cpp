// Debojyoti Das
//NIT Silchar
#include <bits/stdc++.h>
using namespace std;
#define l long long int
void solve()
{
   l n;
   cin>>n;
   if(n==3){
    cout<<-1<<endl;
   }else{
      for (int i = n; i > 4; i--) cout << i << " ";
  cout << "1 2 4 3\n";
   }
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
 