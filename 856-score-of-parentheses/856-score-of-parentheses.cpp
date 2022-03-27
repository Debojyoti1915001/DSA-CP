class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int>st;
        int open=-1;//used as an alternative of '(' since we are using an stack of integer
        for(auto c:s){
            //if opening bracket insert -1
            if(c=='(')st.push(-1);
            //else if you get a closing bracket back we push 1
            else if(c==')'){
                if(st.top()==-1){
                    st.pop();
                    st.push(1);
                //or add the values in the stack till we get a opening bracket
                }else{
                    int val=0;
                    while(st.top()!=-1){
                        val+=st.top();
                        st.pop();
                    }
                    st.pop();
                    //don't forget to double the  value 
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