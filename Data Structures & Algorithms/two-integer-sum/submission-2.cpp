class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int,int> indices;
        for(int i=0; i<n; ++i){
            indices[nums[i]] = i;
        }
        for(int i=0; i<n; ++i){
            int diff = target - nums[i];
            if(indices.count(diff) && indices[diff] != i){
                return {i, indices[diff]};
            }
        }
        return {};
    }
};
