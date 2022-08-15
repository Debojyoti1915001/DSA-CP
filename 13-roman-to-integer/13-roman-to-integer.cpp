class Solution {
public:
    int romanToInt(string s) {
        long long int ans=0;
        int i=0;
        int n=s.length();
        while(i!=n){
        if(s[i]=='I'&&s[i+1]=='V'&&i+1!=n){
            ans+=4;
            i++;
        }else if(s[i]=='I'&&s[i+1]=='X'&&i+1!=n){
            ans+=9;
            i++;
        }else if(s[i]=='X'&&s[i+1]=='L'&&i+1!=n){
            ans+=40;
            i++;
        }else if(s[i]=='X'&&s[i+1]=='C'&&i+1!=n){
            ans+=90;
            i++;
        }else if(s[i]=='C'&&s[i+1]=='D'&&i+1!=n){
            ans+=400;
            i++;
        }else if(s[i]=='C'&&s[i+1]=='M'&&i+1!=n){
            ans+=900;
            i++;
        }    
        else if(s[i]=='M'){
        ans+= 1000;          
        }else if(s[i]=='D'){
            ans+= 500;
        }else if(s[i]=='C'){
            ans+= 100;
        }else if(s[i]=='L'){
            ans+= 50;
        }else if(s[i]=='X'){
            ans+= 10;
        }else if(s[i]=='V'){
            ans+= 5;
        }else{
            ans+= 1;
        }
            i++;
        }
        return ans;
    }
};