class Solution {
public:
    int hammingWeight(uint32_t n) {
        int c=0;
        while(n){
            //drops the lowest set bit
            n=n&(n-1);
            c++;
        }
        return c;
    }
};