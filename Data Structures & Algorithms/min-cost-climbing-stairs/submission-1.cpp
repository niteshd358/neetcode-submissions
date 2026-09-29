class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n+1,-1);
        return findMinCost(n,cost,dp);
    }
    int findMinCost(int i , vector<int>&cost, vector<int>&dp){
        if(i <= 1) return dp[i] = 0;
        int left = dp[i-1] != -1 ? dp[i-1] : dp[i-1] = findMinCost(i-1, cost, dp) + cost[i-1];
        int right = dp[i-2] != -1 ? dp[i-2] : dp[i-2] = findMinCost(i-2, cost, dp) + cost[i-2];
        return dp[i] = min(left,right);
    }
};
