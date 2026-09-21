class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        for(int i=0; i<n; i++){
            int fuel = gas[i] - cost[i];
            if(fuel < 0) continue;
            
            int j = (i + 1) % n ;  // [0 1 2 3 4] [5 6 7 8 9]
            while( j != i){
                fuel += gas[j] - cost[j];
                if(fuel < 0) break;
                j = (j + 1) % n;
            }

            if(j == i) return i;
        }
        return -1;
    }
};
