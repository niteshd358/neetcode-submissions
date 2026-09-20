class Solution {
private:
    bool dfs(int i, vector<int>& nums, unordered_map<int,bool>& memo){
        if(memo.count(i)){
            return memo[i];
        }
        if(i == nums.size() - 1) {
            return true;
        }
        if(nums[i] == 0){
            return false;
        }

        int end = min((int)nums.size()-1, i + nums[i]);

        for(int j=i+1; j<=end; ++j){
            if (dfs(j,nums,memo)) {
                memo[i] = true;
                return true;
            }
        }
        memo[i] = false;
        return false;
    }
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        vector<bool> dp(n,false);
        dp[n-1] = true;

        for(int i = n-2 ; i >= 0; --i){
            int end =  min(n, i+nums[i]+1);
            for(int j=i+1 ; j <end ; j++){
                if(dp[j]){
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[0];
    }
};
