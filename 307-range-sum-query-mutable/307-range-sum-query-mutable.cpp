#define ll int
class NumArray {
public:
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
        return 0;
    }
    if (l <= ss and r >= se) {
        return tree[index];
    }
    int mid = (ss + se) / 2;
    int a = query(l, r, 2 * index, ss, mid);
    int b = query(l, r, 2 * index + 1, mid + 1, se);
    return a+b;

}
    NumArray(vector<int>& nums) {
        n=nums.size();
        a=nums;
        tree.resize(4*n+1);
        build(1, 0, n - 1);
    }
    
    void update(int i, int val) {
         update(i, val, 1, 0, n - 1);
    }
    
    int sumRange(int l, int r) {
        return (ll)query(l, r, 1, 0, n - 1);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */