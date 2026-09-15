class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int productOfAll = 1;
        int countZero = 0;
        int idxOfZero = -1;
        for(int i = 0 ; i< nums.size(); ++i){
            if(nums[i] == 0) {
                countZero++;
                idxOfZero = i;
                continue;
            }
            productOfAll *= nums[i];
        }
        vector<int> result(nums.size(),0);
        if(countZero > 1) return result;
        if(countZero == 1){
            result[idxOfZero] = productOfAll;
            return result;
        }
        for(int i = 0 ; i<nums.size() ; ++i){
            if(nums[i] == 0){
                result[i] = productOfAll;
                continue;
            }
            result[i] = productOfAll / nums[i];
        }
        return result;
    }
};
