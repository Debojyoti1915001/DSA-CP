// Debojyoti Das
//NIT Silchar
#include <bits/stdc++.h>
using namespace std;
#define gc getchar_unlocked
#define fo(i, n) for (l i = 0; i < n; i++)
#define fr(i, a, b) for (int i = a; i <= b; i++)
#define Fo(i, k, n) for (i = k; k < n ? i < n : i > n; k < n ? i += 1 : i -= 1)
#define l long long int
#define si(x) cin >> x
#define ss(s) cin >> s
#define pi(x) cout << x << " "
#define pl(x) cout << x << endl
#define ps(s) cout << s
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

void solve()
{
    l a, b;
    cin >> a >> b;
    string s;
    cin >> s;
    l n = s.length();
    l ans = a;
    vector<pair<char, l>> v;
    l i = 0;
    while (i < n)
    {
        l c = 1;
        while (i + 1 != n && s[i] == s[i + 1])
        {
            c++;
            i++;
        }
        if (v.size() == 0 && s[i] == '0')
        {
            i++;
            continue;
        }
        v.push_back({s[i], c});
        i++;
    }
    if (v.size() != 0 && v[v.size() - 1].first == '0')
        v.pop_back();
    l sz = v.size();
    if (sz == 0)
    {
        cout << 0 << endl;
        return;
    }
    for (l i = 0; i < sz; i++)
    {
        if (v[i].first == '0')
        {
            ans = min(ans + b * v[i].second, ans + a);
        }
    }
    cout << ans << endl;
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
        //            cout<<"Case #"<<i<<": ";
        solve();
    }
    return 0;
}
