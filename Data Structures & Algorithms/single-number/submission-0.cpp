class Solution {
public:
    int singleNumber(vector<int>& nums) {
        // 1101 & 0010 == 0000
        // 1101 ^ 1101 == 0000 ^ 1101 = 1101
        int x = nums[0];
        for(int i=1; i<nums.size(); ++i){
            x = x ^ nums[i];
        }
        return x;
    }
};
