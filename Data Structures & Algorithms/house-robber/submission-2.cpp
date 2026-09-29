class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n,-1);
        return findAmt(n-1,nums,dp);
    }

    int findAmt(int i, vector<int>&nums, vector<int>&dp){
        if(i < 0) return 0;

        if(i == 0 ) return dp[0] = nums[0];

        // rob from curr housr or SKIP
        if(dp[i] != -1) return dp[i];

        int left = findAmt(i-2,nums,dp) + nums[i];
        int right= findAmt(i-1,nums,dp);


        return dp[i] = max(left,right);
    }
};
