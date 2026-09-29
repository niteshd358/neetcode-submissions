class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n+1, -1);
        dp[0] = 0;
        dp[1] = nums[0];

        for(int i=2; i<=n; ++i){
            // rob the current house or SKIP it
            int robCurr = dp[i-2] + nums[i-1];
            int skipCurr= dp[i-1];
            dp[i] = max(robCurr, skipCurr);
        }
        return dp[n];
    }
};
