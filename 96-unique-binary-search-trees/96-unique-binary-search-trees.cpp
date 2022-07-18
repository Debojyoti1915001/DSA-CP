class Solution {
public:
    int numTrees(int n) {
        long long ans=1;
        for(int i=1;i<=n;i++){
            ans=ans*(i+n)/i;
        }
        return ans/(n+1);
    }
};