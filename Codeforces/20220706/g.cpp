#define ll long long
#define all(a) a.begin(),a.end()
#define ff first
#define ss second
#define pb push_back
typedef map<int, int> mii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int,int> pii;
typedef pair<ll, ll> pll;
class Solution {
public:
    long long minSumSquareDiff(vector<int>& aa, vector<int>& bb, int k1, int k2) {
        vector<int> v(100005, 0); 
        for (int i=0; i<aa.size(); i++){ 
            v[abs(aa[i]-bb[i])]++;  
        } 
 
        int count = k1+k2; 
        for (int i=v.size()-1; i>0; i--){ 
            if (count >v[i]){ 
                v[i-1] += v[i]; 
                count -= v[i]; 
                v[i]=0; 
            }else{ 
                v[i-1]+=count; 
                v[i]-=count; 
                count=0; 
                break; 
            } 
        } 
 
        ll res = 0; 
        for (int i=1; i<v.size(); i++){ 
            ll cntp=0; 
            if (v[i]){ 
                cntp=1; 
                cntp*=i; cntp*=i; cntp*=v[i]; 
            } 
            res+=cntp; 
        } 
        return res; 
    }
};