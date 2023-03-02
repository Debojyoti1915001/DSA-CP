class Solution {
public:
    int compress(vector<char>& c) {
        int cnt=0, r=1;
        for(int i=0;i<c.size();i++){
            
            if(i<c.size()-1&& c[i]==c[i+1]) r++;
            else{
                c[cnt]=c[i];cnt++;
                if(r>1){
                    string s=to_string(r);
                    for(auto i:s){
                        c[cnt]=i;
                        cnt++;
                    }
                    r=1;                    
                }
            }
        }        
        return cnt;
    }
};