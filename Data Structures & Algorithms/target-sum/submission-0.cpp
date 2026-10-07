class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        return dfs(0,target,nums);
    }
    
    int dfs(int i, int target, vector<int>&nums){
        
        if(i == nums.size()){
            if(target == 0) return 1;
            else return 0;
        }

        //add
        int add = dfs(i+1,target-nums[i],nums);

        //subtract
        int sub = dfs(i+1, target+nums[i],nums);

        return add+sub;
    }
};
