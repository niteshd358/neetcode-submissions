class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int max_sum = nums[0];
        int curr_sum = 0;
        for(int num : nums){
            if(curr_sum < 0){
                curr_sum = 0;
            }
            curr_sum += num;
            max_sum = max(max_sum, curr_sum);
        }
        return max_sum;
    }
};
