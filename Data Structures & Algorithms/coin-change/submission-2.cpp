class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,-1));
        minCoins(n-1,amount, coins, dp);
        if(dp[n-1][amount] >= 1e9) return -1;
        return dp[n-1][amount];
    }
    int minCoins(int ind, int target, vector<int>&coins, vector<vector<int>>&dp){
        // Impossible target

        if (target < 0) {
            return 1e9;
        }
        if(dp[ind][target] != -1){
            return dp[ind][target];
        }


        if(ind == 0) {
            if(target % coins[ind] == 0) return dp[ind][target] = target/coins[ind];
            else return dp[ind][target]  =1e9;
        }

        // take this coin and stay at same index 
        int take = 1 + minCoins(ind, target-coins[ind], coins, dp); 
        int noTake = 0 + minCoins(ind-1, target, coins, dp);

        return dp[ind][target] = min(take, noTake);
    }
};
