class Solution {
public:
    string longestPalindrome(string s) {
        string result = "";
        for(int i=0; i<s.length(); ++i){
            longestPalFromMid(i,i,s,result); // when odd substring
            longestPalFromMid(i,i+1,s,result); //when even substring
        }
        return result;
    }

    void longestPalFromMid(int i, int j, string& s, string& result){
        while(i>=0 && j<s.length() && s[i] == s[j]){
            i--;
            j++;
        }
        int len = j - i - 1;
        if(len > result.length()){
            result = s.substr(i+1,len);
        }
    }
};
