#include <bits/stdc++.h>
using namespace std;
#define gc getchar_unlocked
#define fo(i, n) for (l i = 0; i < n; i++)
#define fr(i, a, b) for (int i = a; i <= b; i++)
#define Fo(i, k, n) for (i = k; k < n ? i < n : i > n; k < n ? i += 1 : i -= 1)
#define l long long int
#define yes cout << "YES\n"
#define no cout << "NO\n"
#define nl cout << endl
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define clr(x) memset(x, 0, sizeof(x))
#define sortall(x) sort(all(x))
#define tr(it, a) for (auto it = a.begin(); it != a.end(); it++)
#define PI 3.1415926535897932384626
typedef pair<int, int> pii;
typedef pair<l, l> pl;
typedef vector<int> vi;
typedef vector<l> vl;
typedef vector<pii> vpii;
typedef vector<pl> vpl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
template <typename T>

const l mod = 1000000007;
const l N = 3e5, M = N;
int t, k;
string s, u[17] = {"1", "4", "6", "8", "9", "22", "25", "27", "32", "33", "35", "52", "55", "57", "72", "75", "77"};
void solve()
{
    for (int i = 0; i < 17; i++)
    {
        int a = 0;
        for (int j = 0; j < k; j++)
        {
            if (s[j] == u[i][a])
                a++;
        }
        if (a == u[i].size())
        {
            cout << a << endl
                 << u[i] << endl;
            return;
        }
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
    cin >> t;
    for (l i = 1; i <= t; i++)
    {
        cin >> k >> s;
        //            cout<<"Case #"<<i<<": ";
        solve();
    }
    return 0;
}
