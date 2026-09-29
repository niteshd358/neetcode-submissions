class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n+1,-1);
        return findMinCost(n,cost,dp);
    }
    int findMinCost(int i , vector<int>&cost, vector<int>&dp){
        if(i <= 1) return dp[i] = 0;
        if(dp[i] != -1) return dp[i];
        int left = findMinCost(i-1, cost, dp) + cost[i-1];
        int right = findMinCost(i-2, cost, dp) + cost[i-2];
        return dp[i] = min(left,right);
    }
};
