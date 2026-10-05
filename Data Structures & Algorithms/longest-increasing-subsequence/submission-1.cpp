class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,1);
        // 0 3 1 3 2 3
        // 1 1 1 1 1 1
        // 1 1 1 1 2 1
        // 1 1 1 1 2 1
        // 1 1 3 1 2 1
        // 1 1 3 1 2 1
        // 4 1 3 1 2 1
        // if u start from curr posit longest subseq
        for(int i=n-1; i>=0; --i){
            for(int j=i+1; j<n; ++j){
                if(nums[i] < nums[j]){
                    dp[i] = max(dp[i],1+dp[j]);
                }
            }
        }
        int maxlen = 0;
        for(int i=0; i<n; i++){
            maxlen = max(maxlen,dp[i]);
        }
        return maxlen;
    }
};
