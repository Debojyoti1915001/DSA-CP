class Solution {
public:
    int minChanges(int n, int k) {
        int ans=0;
        while(n!=k){
            if(n%2!=k%2 && n%2==1){
                ans++;
            }
            else if(n%2!=k%2 && n%2==0)return -1;
            n=n/2;
            k=k/2;
            
        }
        return ans;
    }
};