class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int>st;
        int open=-1;
        for(auto c:s){
            if(c=='(')st.push(-1);
            else if(c==')'){
                if(st.top()==-1){
                    st.pop();
                    st.push(1);
                }else{
                    int val=0;
                    while(st.top()!=-1){
                        val+=st.top();
                        st.pop();
                    }
                    st.pop();
                    val=val*2;
                    st.push(val);
                }
            }
        }
        int ans=0;
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        return ans;
    }
};