class Solution {
public:
    int countSubstrings(string s) {
        int cnt = 0;
        for(int i=0 ; i<s.length(); ++i){
            cnt += palSubstrFromMid(i,i,s); // cnt if odd length aba
            cnt += palSubstrFromMid(i,i+1,s); //cnt if even length abba
        }
        return cnt;
    }
    int palSubstrFromMid(int i, int j, string &s){
        int cnt = 0;
        while(i>=0 && j<s.length() && s[i] == s[j]){
            cnt++;
            i--;
            j++;
        }
        return cnt; 
    }
};
