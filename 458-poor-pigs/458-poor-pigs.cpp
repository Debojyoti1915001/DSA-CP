class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        int pig=0;
        int rounds=minutesToTest/minutesToDie+1;
        while(buckets>pow(rounds,pig)){
            pig++;
        }
        return pig;
            
    }
};