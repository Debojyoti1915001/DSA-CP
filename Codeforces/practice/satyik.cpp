// Debojyoti Das
//NIT Silchar
#include <bits/stdc++.h>
using namespace std;
bool static comp(pair<char,int>a,pair<char,int>b){
    return a.first>b.first;
}
#define l long long int
void solve()
{
    int k;
    cin>>k;
    string s;
    cin>>s;
    int n=s.length();
    if(k>=s.length()){
        sort(s.begin(),s.end(),greater<char>());
        cout<<s<<endl;
    }else{
        string temp2=s;
        sort(temp2.begin(),temp2.end(),greater<char>());
        vector<pair<char,int>>temp;
        for(int i=0;i<n;i++){
            temp.push_back({s[i],i});
        }
        sort(temp.begin(),temp.end(),comp);
        int i=0;
        while(i!=n){
            if(k==0||temp2==s){
                break;
            }
            if(temp[i].first==s[i]){
                i++;
                continue;
            }
            int idx=temp[i].second;
            swap(s[i],s[temp[i].second]);
            k--;
        }
        cout<<s<<endl;
    }   
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout << fixed;
    cout << setprecision(10);
    //        freopen("timber_input.txt", "r", stdin);
    //        freopen("timber_output.txt", "w", stdout);
    int t = 1;
    //cin >> t;
    for (l i = 1; i <= t; i++)
    {
        //            cout<<"Case #"<<i<<": ";
        solve();
    }
    return 0;
}
