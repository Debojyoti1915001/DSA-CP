class Solution {
public:
    int minChanges(int n, int k) {
        int ans=0;
        while(n!=k){
            if((n&1) != (k&1) && (n&1)==1){
                ans++;
            }
            else if((n&1)!= (k&1) && (n&1) ==0)return -1;
            n=n/2;
            k=k/2;
            
        }
        return ans;
    }
};