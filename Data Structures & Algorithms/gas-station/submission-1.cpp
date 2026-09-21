class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int start = n - 1, end = 0;
        int fuel = gas[start] - cost[start];

        while(start > end){
            if(fuel < 0 ){
                start--;
                fuel += gas[start]-cost[start];
            }else{
                fuel += gas[end] - cost[end];
                end++;
            }
        }

        return fuel >= 0 ? start : -1;
    }
};
