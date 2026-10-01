class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        // sort(coins.begin(),coins.end());
        int ans =  minCoins(n-1,amount, coins);
        if(ans >= 1e9) return -1;
        return ans;
    }
    int minCoins(int ind, int target, vector<int>&coins){
        // Impossible target
        if (target < 0) {
            return 1e9;
        }

        if(ind == 0) {
            if(target % coins[ind] == 0) return target/coins[ind];
            else return 1e9;
        }

        // take this coin and stay at same index 
        int take = 1 + minCoins(ind, target-coins[ind], coins); 
        int noTake = 0 + minCoins(ind-1, target, coins);

        return min(take, noTake);
    }
};
