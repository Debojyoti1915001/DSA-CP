class Solution {
public:
    int uniquePaths(int m, int n) {
        if(n==1||m==1)return 1;
        n--;
        m--;
        if(m<n){
            m=m+n;
            n=m-n;
            m=m-n;
        }
        long res=1;
        for(int i=m+1,j=1;i<=m+n;i++,j++){
            res*=i;
            res/=j;
        }
        return (int)res;
        
    }
};