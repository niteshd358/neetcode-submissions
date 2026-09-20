class Solution {
public:
    bool canJump(vector<int>& nums) {
        int i = 0; 
        while(i<nums.size()){
            if(nums[i] == 0) break;
            i += nums[i]; 
        }
        if(i >= nums.size()-1) return true;
        return false;
    }
};
