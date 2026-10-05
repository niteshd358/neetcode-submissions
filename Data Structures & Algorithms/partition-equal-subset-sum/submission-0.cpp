class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int num : nums) sum += num;

        if(sum % 2) return false;

        return dfs(0, sum/2 , nums);
    }

    bool dfs(int i, int target, vector<int>&nums){
        if(i == nums.size()) return target == 0;

        if(target < 0) return false;

        bool take = dfs(i+1, target-nums[i], nums);
        bool noTake= dfs(i+1, target, nums);

        return take || noTake;
    }
};
