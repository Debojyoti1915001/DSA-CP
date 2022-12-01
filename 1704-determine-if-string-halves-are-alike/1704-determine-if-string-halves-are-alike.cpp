class Solution {
public:
    bool vowel(char c){
        return (c=='a'|| c=='e'|| c=='i'|| c=='o'|| c=='u'|| c=='A'|| c=='E'||c=='I'||c=='O'|| c=='U');
    }
    bool halvesAreAlike(string s) {
        int c1=0,c2=0;
        for(int i=0;i<s.length();i++){
            if(i<s.length()/2){
                if(vowel(s[i]))c1++;
            }else{
                if(vowel(s[i]))c2++;
            }
        }
        return c1==c2;
    }
};