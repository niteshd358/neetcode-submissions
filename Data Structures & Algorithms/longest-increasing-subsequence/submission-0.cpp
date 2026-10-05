class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,1);
        // 0 3 1 3 2 3     9 8 7 6 5
        // 1 2 2 3 3 4     0 0 0 0 0
        // dp[0] = 1; 
        for(int i=1; i<n; ++i){
            for(int j=i-1; j>=0 ; --j){
                if(nums[j] < nums[i]){
                    dp[i] = dp[j] + 1;
                    break; 
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
