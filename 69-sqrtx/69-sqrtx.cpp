class Solution {
public:
    int mySqrt(int x) {
        if(x==0)return 0;
        int lo=1,hi=x,ans=-1;
        while(lo<=hi){
            int mid=(hi-lo)/2+lo;
            if(x/mid>=mid){
                ans=mid;
                lo=mid+1;
            }else{
                hi=mid-1;
            }
        }
        return ans;
    }
};