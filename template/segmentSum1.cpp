//Range Max using segment tree
//Also including point update
#include<bits/stdc++.h>


using namespace std;


#define ll long long
#define nl '\n'


vector<ll> a;
vector<ll> tree;
ll n;
void build(ll index, ll s, ll e) {
    if (s == e) {
        tree[index] = a[s];
        return;
    }
    ll mid = (s + e) >> 1;
    build(2 * index, s, mid);
    build(2 * index + 1, mid + 1, e);
    tree[index] = tree[2 * index]+tree[2 * index + 1];
}
//POINT UPDATE
void update(ll i, ll val, ll index, ll ss, ll se) {
    if (i<ss or i>se) {
        return;
    }
    if (ss == se) {
        tree[index] = val;
        return;
    }
    //otherwise
    int mid = (ss + se) / 2;
    update(i, val, 2 * index, ss, mid);
    update(i, val, 2 * index + 1, mid + 1, se);
    tree[index] = tree[2 * index]+tree[2 * index + 1];

}
//RANGE QUERY
ll query(ll l, ll r, ll index, ll ss, ll se) {
    if (r<ss or l>se) {
        return INT_MIN;
    }
    if (l <= ss and r >= se) {
        return tree[index];
    }
    int mid = (ss + se) / 2;
    int a = query(l, r, 2 * index, ss, mid);
    int b = query(l, r, 2 * index + 1, mid + 1, se);
    return a+b;

}
void solve() {
    cin >> n;
    a.resize(n);
    tree.resize(4 * n + 1);
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
    }
    build(1, 0, n - 1);
    ll q;
    cin >> q;
    for (ll i = 0; i < q; i++) {
        ll type;
        cin >> type;
        if (type == 1) {
            ll i, val;
            cin >> i >> val;
            update(i, val, 1, 0, n - 1);
        }
        else {
            ll l, r;
            cin >> l >> r;
            cout << query(l, r, 1, 0, n - 1) << nl;
        }

    }
}
int main()
{

    //FIO();
    ll t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
}