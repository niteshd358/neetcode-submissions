class Solution {
    vector<vector<int>> dp;
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        dp.assign(n,vector<int>(amount+1,-1));
        return dfs(0,amount,coins);
    }
    int dfs(int i, int target, vector<int>&coins){
        if(target == 0) return 1;

        if(i>=coins.size()) return 0;
        
        if(target < 0) return 0;

        if(dp[i][target] != -1){
            return dp[i][target];
        }
        //take
        int take = dfs(i,target-coins[i],coins);
        // not take
        int notake = dfs(i+1,target, coins);

        return dp[i][target] = take + notake;
    }
};
