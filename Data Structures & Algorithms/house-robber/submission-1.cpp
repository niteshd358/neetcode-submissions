class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        return findAmt(n-1,nums);
    }

    int findAmt(int i, vector<int>&nums){
        if(i < 0) return 0;

        if(i == 0 ) return nums[0];

        // rob from curr housr or not
        return max(findAmt(i-2,nums)+nums[i],findAmt(i-1,nums));
    }
};
