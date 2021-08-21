#include <bits/stdc++.h>
using namespace std;
void solve()
{
    string key, decode;
    cin >> key >> decode;
    vector<int> val;
    for (int i = 0; i < key.size(); i++)
    {
        val.push_back(key[i] - 'a');
    }
    int k = 0, n = key.size();
    for (int i = 0; i < decode.size(); i++)
    {
        decode[i] = (decode[i] + val[k] - 'a') % 26 + 'a';
        k = (k + 1) % n;
    }
    cout << decode << endl;
}
int main()
{
    int t = 1;
    for (int i = 1; i <= t; i++)
    {
        //            cout<<"Case #"<<i<<": ";
        solve();
    }
    return 0;
}
