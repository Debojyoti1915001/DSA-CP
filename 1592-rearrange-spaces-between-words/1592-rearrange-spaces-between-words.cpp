class Solution {
public:
    string reorderSpaces(string text) {
        string ans,word;
        vector<string>words;
        int space=0;
        for(auto t:text){
           if(t==' '){
               if(word.size())words.push_back(word);
               word="";
               space++;
           }else{
               word+=t;
           }
            
        }
        if(word.size())words.push_back(word);
        if(words.size()==1){
            return words[0]+string(space,' ');
        }
        int per=space/(words.size()-1);
        int rem=space%(words.size()-1);
        for(int i=0;i<words.size();i++){
            if(i==words.size()-1){
                ans+=words[i]+string(rem,' ');
            }else{
                ans+=words[i]+string(per,' ');
            }
        }
        return ans;
    }
};