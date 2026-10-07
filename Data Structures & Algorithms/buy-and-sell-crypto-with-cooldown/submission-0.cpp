class Solution {
    vector<vector<int>>dp;
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        dp.resize(n,vector<int>(2,-1));
        return dfs(0,true,prices);
    }
    int dfs(int i, bool canBuy, vector<int>&prices){
        if(i >= prices.size()) return 0;

        if(dp[i][int(canBuy)] != -1) return dp[i][int(canBuy)];

        int cooldown = dfs(i+1, canBuy, prices);

        if(canBuy){
            int buy = dfs(i+1, false,prices) - prices[i];
            return dp[i][canBuy] = max(buy,cooldown);
        }else{
            int sell = dfs(i+2,true,prices) + prices[i];
            return dp[i][canBuy] = max(sell,cooldown);
        }
    }
};
