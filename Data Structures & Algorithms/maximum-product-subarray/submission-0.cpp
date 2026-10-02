class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int suffix = 1;
        int prefix = 1;
        int res = nums[0];
        for(int i=0; i<n; ++i){
            prefix *= nums[i];
            suffix *= nums[n-i-1];
            res = max(res, max(prefix,suffix)); 
        }
        return res;
    }
};
