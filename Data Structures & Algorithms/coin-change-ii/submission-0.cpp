class Solution {
public:
    int change(int amount, vector<int>& coins) {
        return dfs(0,amount,coins);
    }
    int dfs(int i, int target, vector<int>&coins){
        if(i>=coins.size()) return 0;
        if(target < 0) return 0;

        if(target == 0) return 1;
        //take
        int take = dfs(i,target-coins[i],coins);
        // not take
        int notake = dfs(i+1,target, coins);

        return take + notake;
    }
};
