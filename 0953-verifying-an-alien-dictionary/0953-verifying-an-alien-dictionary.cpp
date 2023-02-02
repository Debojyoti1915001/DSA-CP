class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        vector<int> order_map(26, -1);

        for(int i = 0;i<26;i++)
        {
            order_map[order[i]-97] = i;
        }

        for(int i = 0;i<words.size()-1;i++)
        {
            string word1 = words[i];
            string word2 = words[i+1];

            int len = min(word1.length(), word2.length());
            int j;
            for( j = 0;j<len;j++)
            {
                if(order_map[word1[j]-97]>order_map[word2[j]-97]) 
                                 //first word is larger
                return false;
                else if(order_map[word1[j]-97]<order_map[word2[j]-97])
                break;
            }

            if(j==len) //the words are same so far, use lengths
            if(word1.length()>word2.length())
            return false;
        }
        return true;
    }
};