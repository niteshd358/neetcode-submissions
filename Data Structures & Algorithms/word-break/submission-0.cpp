class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> st;
        int maxLen = 0;
        for(auto word : wordDict){
            st.insert(word);
            maxLen = max(maxLen,(int)word.length());
        }
        
        int n = s.length();

        // dp[i] = true if s[0...i-1] can be segmented 
        vector<bool> dp(n+1);
        
        dp[0] = true; //empty string can be segmented

        for(int i=1; i<=n; i++){
            // Check only words whose length <= maxLen
            for (int j = i - 1; j >= max(0, i - maxLen); j--) {

                // If s[0...j-1] is valid
                // and s[j...i-1] is a dictionary word
                if (dp[j] && st.count(s.substr(j, i - j))) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[n];
    }
};
