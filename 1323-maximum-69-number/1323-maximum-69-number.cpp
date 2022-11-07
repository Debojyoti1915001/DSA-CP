class Solution {
public:
    int maximum69Number (int num) {
        string cur=to_string(num);
        for(int i=0;i<cur.size();i++){
            if(cur[i]=='6'){
                cur[i]='9';
                break;
            }
        }
        
        return stoi(cur);
    }
};