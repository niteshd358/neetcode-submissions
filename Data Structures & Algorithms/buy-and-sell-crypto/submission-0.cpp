class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy = 0;
        int sell = 0;
        int profit=0;
        sell++;
        while(sell<prices.size()){
            if(prices[sell] < prices[buy]){
                buy = sell;
                sell++;
            }
            else{
                profit = max(profit, prices[sell] - prices[buy]);
                sell++;
            }
        }
        return profit;
    }
};
