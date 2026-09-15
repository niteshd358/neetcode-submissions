class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        int total_subsets = (1<<n);
        vector<vector<int>> ans;
        ans.reserve(total_subsets);
        for(int mask = 0 ; mask < total_subsets ; mask++){
            vector<int> ds;
            for(int i = 0 ; i< n ; i++){
                if(mask & (1<<i)){
                    ds.push_back(nums[i]);
                }
            }
            ans.push_back(ds);
        }
        return ans;
    }
};
