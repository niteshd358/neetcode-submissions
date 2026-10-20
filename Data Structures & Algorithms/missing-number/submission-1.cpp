class Solution {
public:
    int missingNumber(vector<int>& nums) {
        // a ^ a = 0
        // a ^ 0 = a
        int n = nums.size(); // 0 1 2 4
        int res = 0;
        for(int i=0; i<=n; ++i){
            res = res ^ i;
        }
        for(int i=0; i<n; ++i){
            res = res ^ nums[i];
        }
        return res;
    }
};
