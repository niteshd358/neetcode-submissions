class Solution {
public:
    int numDecodings(string s) {
        int n = s.length();
        vector<int> dp(n,-1);
        return count(0,s,dp);
    }
    int count(int i, string &s, vector<int>&dp){
         // Reached the end -> one valid decoding
        if (i == s.length()) {
            return 1;
        }
        // Leading zero -> invalid
        if (s[i] == '0') {
            return 0;
        }
        // Already calculated
        if (dp[i] != -1) {
            return dp[i];
        }
        
        // take one digit
        int ways = count(i+1,s,dp);

        // take two digits if valid
        if(i+1 < s.length()) {
            if(s[i]=='1' || (s[i]=='2') && (s[i+1] <= '6')){
                ways += count(i+2,s,dp);
            }
        }
        return dp[i] = ways;
    }
};
