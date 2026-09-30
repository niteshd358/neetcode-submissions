class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        vector<int> dp(n+1, 0);
        int prev2 = 1; // if size is 0 only one way 
        int prev1 = s[0] == '0' ? 0 : 1;
        // waysToDecode[i] = waysToDecode[i-1](if one digit valid) + waysToDecode[i-2](if two Digits valid)
            int curr = 0;
        for(int i=2; i<=n; ++i){
            int oneDigit = stoi(s.substr(i-1,1)); // substr(startIndex, length)
            int twoDigit = stoi(s.substr(i-2,2));;// substr(startIndex, length)

            if(oneDigit >= 1){
                curr += prev1;
            }
            if(twoDigit >= 10 && twoDigit <= 26){
                curr += prev2;
            }

            prev2 = prev1;
            prev1 = curr;
            curr = 0;
        }
        return prev1;  
    }
};
