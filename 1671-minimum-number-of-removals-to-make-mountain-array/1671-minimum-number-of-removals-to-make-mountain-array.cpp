class Solution {
public:
    int minimumMountainRemovals(vector<int>& v) {
     int n=v.size();
    if(n<=1)return 0;
    vector<int>a(n),b(n),inc(n+1,INT_MAX),dec(n+1,INT_MAX);
    inc[0]=INT_MIN;
    dec[0]=INT_MIN;
    for(int i=0;i<n;i++){
        int idx=lower_bound(inc.begin(),inc.end(),v[i])-inc.begin();
        a[i]=idx-1;
        inc[idx]=v[i];
    }
    for(int i=n-1;i>=0;i--){
        int idx=lower_bound(dec.begin(),dec.end(),v[i])-dec.begin();
        b[i]=idx-1;
        dec[idx]=v[i];
    }
    int ans=INT_MAX;
    for(int i=0;i<n;i++){
        if(a[i]&&b[i])ans=min(ans,n-(a[i]+b[i]+1));
    }
    return ans;   
    }
};