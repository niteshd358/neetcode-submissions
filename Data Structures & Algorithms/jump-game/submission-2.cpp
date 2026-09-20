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
        unordered_map<int,bool> memo;
        return dfs(0,nums,memo);
    }
};
