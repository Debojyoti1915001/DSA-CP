// https://leetcode.com/problems/find-all-anagrams-in-a-string/

class Solution {
public:
    vector<int> findAnagrams(string txt, string pat) {
	    vector<int> ans;
        int k=pat.length();
	    int a[26],b[26];
	    for(int i=0;i<26;i++)a[i]=0;
	    for(int i=0;i<26;i++)b[i]=0;
	    for(int i=0;i<pat.size();i++)b[pat[i]-'a']++;
	    int i=0,j=0;
	    while(j<txt.size()){
	        a[txt[j]-'a']++;
	        if(j-i+1<k)j++;
	        else if(j-i+1==k){
	            int flag=0;
	            for(int t=0;t<26;t++){
	                if(a[t]!=b[t]){
	                    flag=1;
	                    break;
	                }
	            }
	            if(flag==0){
	                ans.push_back(i);
	            }
	            a[txt[i]-'a']--;
	            i++,j++;
	        }
	    }
	    return ans;
    }
};