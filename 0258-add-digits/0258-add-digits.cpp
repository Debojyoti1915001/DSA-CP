class Solution {
public:
    int addDigits(int num) {
        int ans=0;
        string cur=to_string(num);
        if(cur.size()==1)return num;
        for(int i=0;i<cur.size();i++){
            ans+=cur[i]-'0';
        }
        return addDigits(ans);
    }
};