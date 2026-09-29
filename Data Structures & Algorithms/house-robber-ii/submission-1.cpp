class Solution {
public:
    int rob(vector<int>& nums) {
        // can take first home or last home and use robI
        int n = nums.size();
        if(n==1) return nums[0];
        if(n==2) return max(nums[0],nums[1]);

        return max(robI(0,n-2,nums),robI(1,n-1,nums));
    }
    int robI(int st, int end, vector<int>&nums){
        vector<int>dp(nums.size(),-1);
        dp[st] = nums[st];
        dp[st+1] = max(nums[st],nums[st+1]);
        for(int i=st+2; i<=end; i++){
            // rob curr house or SKIP it
            int rob = dp[i-2] + nums[i];
            int skip = dp[i-1];
            dp[i] = max(rob, skip);
        }
        return dp[end];
    }
};
