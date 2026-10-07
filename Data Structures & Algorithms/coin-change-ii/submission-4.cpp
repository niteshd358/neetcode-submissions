class Solution {
    vector<vector<int>> dp;
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        dp.assign(n+1,vector<int>(amount+1,0));
    
        // Base case:
        // There is exactly 1 way to make amount 0:
        // choose nothing.
        for (int i = 0; i <= n; i++) {
            dp[i][0] = 1;
        }

        for(int i=n-1; i>=0; --i){
            for(int target=1; target<=amount; target++){
                //NOT tAKE
                int notake = dp[i+1][target];
                // take
                int take = 0;
                if(target >= coins[i]){
                    take = dp[i][target - coins[i]];
                }
                dp[i][target] = take + notake;
            }
        }

        return dp[0][amount];
    }
};
