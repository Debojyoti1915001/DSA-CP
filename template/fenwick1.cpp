#include<bits./stdc++.h>
using namespace std;
#define MAX 200005
long long bit[MAX];
ll n;
long long query(int indx) {
    long long sum = 0;
    while (indx) {
        sum += bit[indx];
        indx -= (indx & -indx);
    }
    return sum;
}

void update(int indx, int x) {
    assert(indx != 0);
    while (indx < MAX) {
        bit[indx] += x;
        indx += (indx & -indx);
    }
}
void solve() {
    int n;
    cin >> n;
    ll a[n + 1];
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        update(i, a[i]);
    }
    for (int i = 1; i <= n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
    ll q;
    cin >> q;
    while (q--) {
        ll type;
        cin >> type;
        if (type == 1) {
            ll idx, val;
            cin >> idx >> val;
            update(idx, val - a[idx]);//very important
            a[idx] = val;
            for (int i = 1; i <= n; i++) {
                cout << a[i] << " ";
            }
            cout << endl;
        }
        else if (type == 2) {
            ll left, right;
            cin >> left >> right;//1 based indexing of left
            //and right
            cout << query(right) - query(left - 1);
        }
    }
}
int main()
{
    FIO();
    ll t;
    cin >> t;
    while (t--) {
        solve();
    }
}