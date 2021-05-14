#include <bits/stdc++.h>
#define l long long int
using namespace std;
int pres(char a){
if(a=='+'||a=='-'){
    return 1;
}
if(a=='*'||a=='/'){
    return 2;
}
if(a=='^'){
    return 3;
}
return -1;
}
int infixToPostfix(string s){
stack<char> st;
st.push('N');
string ans;
l ll=s.length();
for(l i=0;i<ll;i++){
    if((s[i]>='a'&&s[i]<='z')||(s[i]>='A'&&s[i]<='Z')){
        ans+=s[i];
    }
    else if(s[i]=='('){
        st.push(s[i]);
       }
    else if(s[i]==')'){
        while(st.top()!='('&&st.top()!='N'){
                char c=st.top();
                st.pop();
                ans+=c;
              }
              if(st.top()=='('){
        //            cout<<"YO";
                    char c = st.top();
                    st.pop();
                 }
       }
       else {
        while(st.top()!='N'&&pres(s[i])<=pres(st.top())){
            char c=st.top();
            st.pop();
            ans+=c;
        }
        st.push(s[i]);
       }}
       while(st.top()!='N'){
        char c=st.top();
        st.pop();
        ans+=c;
       }

reverse(ans.begin(),ans.end());
cout<<ans<<endl;
}
int main()
{
    //string exp = "a+b*(c^d-e)^(f+g*h)-i";
    string exp ="(a-b/c)*(a/k-l)";
    reverse(exp.begin(),exp.end());
    for(l i=0;i<exp.length();i++){
        if(exp[i]=='('){
            exp[i]=')';
           }
           else if(exp[i]==')'){
            exp[i]='(';
           }
    }
    infixToPostfix(exp);
    return 0;
}
