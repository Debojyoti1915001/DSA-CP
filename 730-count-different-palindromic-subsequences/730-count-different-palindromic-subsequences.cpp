int memo[1001][1001][4];
class Solution {
public:
    string S;
    int mod=1e9+7;
    
    int dp(int start,int end,int alpha){
        if(start>end){
            return 0;
        }
        if(start==end){
            if(S[start]==alpha+'a')return 1;
            return 0;
        }
        if(memo[start][end][alpha]!=-1)return memo[start][end][alpha];
        int dev=0;
        if(S[start]==S[end]&&S[start]==alpha+'a'){
            dev=2;
            for(int i=0;i<4;i++)
                dev=(dev+dp(start+1,end-1,i))%mod;
        }else{
            dev= (dev + dp(start,end-1,alpha))%mod;
			dev= (dev + dp(start+1,end,alpha))%mod;
			dev= (dev - dp(start+1,end-1,alpha))%mod;
			if(dev<0)dev+=mod;
        }
        return memo[start][end][alpha]=dev;
        
    }
    int countPalindromicSubsequences(string _S) {
		S=_S;
		memset(memo,-1,sizeof(memo));
		int ans=0;
		
		for(int i=0;i<4;i++)
			ans= (ans + dp(0, S.size()-1, i))%mod;
		
		return ans;        
	}
};