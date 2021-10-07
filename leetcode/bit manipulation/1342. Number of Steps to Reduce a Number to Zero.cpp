// https://leetcode.com/problems/number-of-steps-to-reduce-a-number-to-zero/

class Solution {
public:
    int numberOfSteps(int num) {
        int c=0;
        while(num){
            if(num&1){
                num--;
                c++;
            }else{
                num=num/2;
                c++;
            }
        }
        return c;
    }
};