class Solution {
public:
    bool reorderedPowerOf2(int n) {
        string num=to_string(n);
        sort(num.begin(),num.end());
        for(int i=0;i<32;i++){
            string cur=to_string(1<<i);
            sort(cur.begin(),cur.end());
            if(cur==num)return true;
        }
        return false;
    }
};