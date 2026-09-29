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
        int len = j-i-1; //if odd len = -1, if even len = 0
        while(i>=0 && j<s.length() && s[i] == s[j]){
            i--;
            j++;
            len = len + 2;
        }
        if(len > result.length()){
            result = s.substr(i+1,len);
        }
    }
};
