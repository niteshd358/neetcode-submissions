class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(nums);
        for(int i=1; i<n; ++i){
            dp[i] = max(nums[i],nums[i]+dp[i-1]);
        }
        return *max_element(dp.begin(),dp.end());
    }
};
