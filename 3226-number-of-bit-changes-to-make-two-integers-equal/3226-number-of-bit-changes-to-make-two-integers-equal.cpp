class Solution {
public:
    int minChanges(int n, int k) {
        int ans=0;
        while(n!=k){
            if(n%2!=k%2 && n%2==1){
                ans++;
                n=n/2;
                k=k/2;
            }else if(n%2==k%2)
            {
                n=n/2;
                k=k/2;
            }
            else return -1;
            
        }
        return ans;
    }
};