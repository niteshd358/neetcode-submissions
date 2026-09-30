class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        vector<int> dp(n+1, 0);
        dp[0] = 1; // if size is 0 only one way 
        dp[1] = s[0] == '0' ? 0 : 1;

        // waysToDecode[i] = waysToDecode[i-1](if one digit valid) + waysToDecode[i-2](if two Digits valid)
        for(int i=2; i<=n; ++i){
            int oneDigit = stoi(s.substr(i-1,1)); // substr(startIndex, length)
            int twoDigit = stoi(s.substr(i-2,2));;// substr(startIndex, length)

            if(oneDigit >= 1){
                dp[i] += dp[i-1];
            }
            if(twoDigit >= 10 && twoDigit <= 26){
                dp[i] += dp[i-2];
            }
        }
        return dp[n];  
    }
};
