class Solution {
public:
    vector<vector<int>> dp;
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int num : nums) sum += num;

        if(sum % 2) return false;

        dp.resize(nums.size(),vector<int>(sum/2 + 1,-1));

        return dfs(0, sum/2 , nums);
    }

    bool dfs(int i, int target, vector<int>&nums){
        if(i == nums.size()) return target == 0;

        if(target < 0) return false;

        if(dp[i][target] != -1){
            return dp[i][target];
        }
        bool take = dfs(i+1, target-nums[i], nums);
        bool noTake= dfs(i+1, target, nums);

        return dp[i][target] = (take || noTake);
    }
};
