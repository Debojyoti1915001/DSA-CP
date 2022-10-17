class Solution {
public:
    bool canCross(vector<int>& stones) {
        unordered_map<int,unordered_set<int>>m;
        for(auto &i:stones){
            m[i].insert(0);
        }
        m[0].insert(1);
        for(int &i:stones){
            unordered_set<int>cur=m[i];
            for(auto &j:cur){
                if(j<=0)continue;
                int pos=i+j;
                if(pos==stones.back())return true;
                if(m.count(pos)){
                    m[pos].insert(j);
                    m[pos].insert(j+1);
                    m[pos].insert(j-1);
                }
            }
        }
        return false;
    }
};