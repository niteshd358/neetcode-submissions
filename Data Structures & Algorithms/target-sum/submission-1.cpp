class Solution {
    vector<vector<int>>dp;
    int offset;
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int sum = accumulate(nums.begin(),nums.end(),0);

        // Target is unreachable
        if (abs(target) > sum) return 0;

        offset = sum;
        
        dp.assign(n,vector<int>(2*sum+1,-1));

        return dfs(0,target,nums);
    }
    
    int dfs(int i, int target, vector<int>&nums){
        
        if(i == nums.size()){
            if(target == 0) return 1;
            else return 0;
        }

        if (target < -offset || target > offset) return 0;

        int index = target + offset; 
        // target can range from -sum to +sum.
        // Adding offset (= sum) shifts the range to [0, 2*sum].

        if(dp[i][index] != -1){
            return dp[i][index];
        }

        //add
        int add = dfs(i+1,target-nums[i],nums);

        //subtract
        int sub = dfs(i+1, target+nums[i],nums);

        return dp[i][index] = add+sub;
    }
};
