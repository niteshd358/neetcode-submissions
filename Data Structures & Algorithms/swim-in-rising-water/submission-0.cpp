class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> dp;
        dp = grid;
        for(int i=1; i<n; ++i){
            for(int j=1; j<n; ++j){
                int min_of_above = min(dp[i-1][j],dp[i][j-1]);
                dp[i][j] = max(dp[i][j], min_of_above);
            }
        }
        return dp[n-1][n-1];
    }
};
