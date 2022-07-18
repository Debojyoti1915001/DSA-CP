class Solution {
public:
     int minInsertions(string t) {
        
        int top=0,ans=0;
        int n = t.length();
        for(int i=0;i<n;i++){
            char c = t[i];
            if(c=='(')
                top++;
            else{
                if(i+1<n && t[i+1]==')') i++;
               else ans++;
                
                if(top==0) ans++;
                else top--;
            }
        }

        return ans+2*top;
    }
};