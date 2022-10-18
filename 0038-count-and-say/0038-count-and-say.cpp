class Solution {
public:
string countAndSay(int n) {
        string s="1";
        for(int i=1;i<n;i++){
            int sz=s.length();
            for(int j=1;j<=sz;j++){
                int c=1;
                char temp;
                temp=s[j-1];
                while(s[j]==s[j-1]&&j!=sz){
                    c++;
                    temp=s[j-1];
                    j++;
                }
                char t=c+'0';
                s.push_back(t);
                s.push_back(temp);
            }
            s=s.substr(sz,s.length());
            //cout<<s<<"  "<<i<<endl;
        }
        return s;
}
};