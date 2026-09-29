class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        return findAmt(n-1,nums);
    }

    int findAmt(int i, vector<int>&nums){
        if(i <= 1 ) return nums[i];
        int maxAmt = INT_MIN;
        for(int j = i-2; j >= 0 ; j--){
            maxAmt = max(maxAmt,findAmt(j,nums) + nums[i]);
        }
        
        return maxAmt;
    }
};
