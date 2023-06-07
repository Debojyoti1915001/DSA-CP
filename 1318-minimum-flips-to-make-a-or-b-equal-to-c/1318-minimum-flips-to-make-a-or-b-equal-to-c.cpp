class Solution {
public:
    int minFlips(int a, int b, int c) {
        int res=0;
        while(a||b||c){
            int x=a&1,y=b&1,z=c&1;
            if((x|y)!=z){
                if(x&&y)res+=2;
                else res++;
            }
            a=a>>1,b=b>>1,c=c>>1;
        }
        return res;
    }
};