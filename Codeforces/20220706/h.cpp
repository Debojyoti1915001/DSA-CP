class Solution {
public:
    bool canChange(string start, string target) {
        int p= 0, q = 0,r = 0, s = 0;
        for(auto i : start) { 
            if(i == 'L') p++;
            else if(i == 'R') q++;
        }
        for(auto i : target) { 
            if(i == 'L') r++;
            else if(i == 'R') s++;
        }
        if(p==r and q==s){
        vector<int> v1,v2;
           for(int i = 0;i<start.size();i++){ 
                if(start[i] != '_') {
                    v1.push_back(i);
                }
            }
            for(int i = 0;i<start.size();i++){ 
                if(target[i] != '_') {
                    v2.push_back(i);
                }
            }
            bool flag = 1;
            for(int i = 0;i<v1.size();i++){ 
                if(start[v1[i]] != target[v2[i]]){ 
                    flag = 0;
                }
                else { 
                    if(start[v1[i]] == 'L'){ 
                        if(v1[i] < v2[i]){
                            flag = 0;
                        } 
                        
                    }else { 
                        if(v1[i] > v2[i]){
                            flag=0;
                        }   
                    }
                }
            }
            if(flag) {
                return true;
            }
            else{
                  return false;
            }
        }
        return false;
            
           
    }
};