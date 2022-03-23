class Solution {
public:
    int brokenCalc(int s, int t) {
        int ans=0;
        while(s<t){
            if(t%2==0){
                ans++;
                t=t/2;
            }else{
                ans+=((t/2)+1)*2-t;
                t=((t/2)+1)*2;
            }
        }
        if(s>t){
            ans+=s-t;
        }
        return ans;
    }
};