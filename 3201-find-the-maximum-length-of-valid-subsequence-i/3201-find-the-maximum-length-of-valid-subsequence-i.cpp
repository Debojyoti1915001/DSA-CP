class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int alte=0,alto=0,e=0,o=0;
        int fe=1,fo=1;
        for(auto &i: nums){
            if(i%2==0){
                e++;
                if(fe){
                    fe=0;
                    alte++;
                }
                if(!fo){
                    fo=1;
                    alto++;
                }
            }else{
                o++;
                if(fo){
                    fo=0;
                    alto++;
                }
                if(!fe){
                    fe=1;
                    alte++;
                }
            }
        }
        return max(max(e,o),max(alte,alto));
    }
};