class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        return findMinCost(n,cost);
    }
    int findMinCost(int i , vector<int>&cost){
        if(i <= 1) return 0;
        // int right = INT_MAX;
        int left = findMinCost(i-1, cost) + cost[i-1];
        int right = findMinCost(i-2, cost) + cost[i-2];
        return min(left,right);
    }
};
