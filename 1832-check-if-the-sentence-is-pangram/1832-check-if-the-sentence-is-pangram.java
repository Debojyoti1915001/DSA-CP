class Solution {
    public boolean checkIfPangram(String sentence) {
        int []cnt=new int[26];
        Arrays.fill(cnt,0);
        for(char i:sentence.toCharArray()){
            cnt[i-'a']++;
        }
        for(int i:cnt)
            if(i==0)return false;
        return true;
    }
}