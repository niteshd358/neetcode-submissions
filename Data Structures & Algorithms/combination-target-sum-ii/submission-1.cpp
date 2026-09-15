class Solution {
void comb_sum_II(int indx, int target, vector<int>&nums, vector<int>&ds,vector<vector<int>>&ans){
    if(target == 0){
        ans.push_back(ds);
        return;
    }
    if(indx >= nums.size() || target < 0 ) return;
    //picking
    for (int i = indx; i < nums.size(); ++i) {
            // Skip duplicates at the same recursive level
            if (i > indx && nums[i] == nums[i - 1]) continue;
            
            // Optimization: Since the array is sorted, if nums[i] > target, 
            // subsequent elements will also be > target, so we can stop.
            if (nums[i] > target) break;
            
            ds.push_back(nums[i]);
            comb_sum_II(i + 1, target - nums[i], nums, ds, ans);
            ds.pop_back();
        }
}
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int>ds;
        sort(candidates.begin(),candidates.end());
        comb_sum_II(0,target,candidates,ds,ans);
        return ans;
    }
};
