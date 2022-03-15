class Solution {
public:
    int minimumDeletions(string s) {
//         Traverse string s, for each char ch:
// (1) If it's b, we don't know whether to delete it or not, only increase bCnt by 1.
// (2) If it's a, we will make deletion only when bCnt is > 0, which means there're b preserved before and has no way to be replaced by traversed a. We might delete current a, or delete previous b, but we don't know yet since this is decided by furture remainig chars. But no matter what we delete, the deletion cnt res will always increase by 1. Use the greedy idea, even if we delete current a, still decrease bCnt by 1 to indicate this b can be replaced by a if later we need it to be replaced
//one more approach is to have a count array from back and find the number of b in front then the ans is min of ans and the count of later a's and present b

//         int bCnt = 0;
//         int res = 0;
//         for (char& ch : s) {
//             if (ch == 'a' && bCnt > 0) {
//                 bCnt--;
//                 res++;
//             }
//             if (ch == 'b') {
//                 bCnt++;
//             }
//         }
//         return res;
        int countA=count(s.begin(),s.end(),'a');//count of 'a' in front
        int countB=0;//count of 'b' in back
        int ans=countA;//max ans is when we remove all the elements
        for(auto c:s){
            countA-=c=='a';
            countB+=c=='b';
            ans=min(ans,countA+countB);
            //i.e. remove all the prev 'b' and all the upcomming 'a'
        }
        return ans;
    }
};