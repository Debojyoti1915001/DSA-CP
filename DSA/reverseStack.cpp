#include <bits/stdc++.h>
using namespace std;
stack<char> st;
void insertBottom(char x)
{
    if (st.size() == 0)
        st.push(x);
    else
    {
        char a = st.top();
        st.pop();
        insertBottom(x);
        st.push(a);
    }
}
void reverseStk()
{
    if (st.size() > 0)
    {
        char x = st.top();
        st.pop();
        reverseStk();
        insertBottom(x);
    }
}
int main()
{
    st.push('1');
    st.push('2');
    st.push('3');
    st.push('4');
    int n = st.size();
    reverseStk();
    for (int i = 0; i < n; i++)
    {
        cout << st.top() << " ";
        st.pop();
    }
}