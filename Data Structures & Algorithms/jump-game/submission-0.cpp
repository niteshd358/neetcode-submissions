class Solution {
public:
    bool canJump(vector<int>& nums) {
        int i = 0; 
        while(i<nums.size()){
            if(i == nums.size()-1) return true;
            if(nums[i] == 0) return false;
            i += nums[i]; 
        }
        return false;
    }
};
