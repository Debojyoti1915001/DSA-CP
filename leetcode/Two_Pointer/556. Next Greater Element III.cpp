// https://leetcode.com/problems/next-greater-element-iii/

class Solution {
public:
    int nextGreaterElement(int n) {
        // vector<int>v;
        // if(n>INT_MAX)return -1;
        // long long int ans=0;
        // while(n){
        //     int temp=n%10;
        //     v.push_back(temp);
        //     n=n/10;
        // }
        // if(is_sorted(v.begin(),v.end()))return -1;
        // reverse(v.begin(),v.end());
        // int ansi=0,ansj=0;
        // for(int i=0;i<v.size();i++){
        //     for(int j=i+1;j<v.size();j++){
        //         if(v[i]<v[j]){
        //             ansi=i;
        //             ansj=j;
        //         }
        //     }
        // }
        // swap(v[ansi],v[ansj]);
        // sort(v.begin()+ansi+1,v.end());
        // for(int i=0;i<v.size();i++){
        //     ans=ans*10;
        //     ans+=v[i];
        //     if(ans>INT_MAX)return -1;
        // }
        // if(ans>INT_MAX)return -1;
        // return ans;
        auto digits = to_string(n);
    next_permutation(begin(digits), end(digits));
    auto res = stoll(digits);
    return (res > INT_MAX || res <= n) ? -1 : res;
    }
};