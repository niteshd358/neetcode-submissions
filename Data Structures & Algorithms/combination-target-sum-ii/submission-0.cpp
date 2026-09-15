class Solution {
void comb_sum_II(int indx, int target, vector<int>&nums, vector<int>&ds,vector<vector<int>>&ans){
    if(target == 0){
        ans.push_back(ds);
        return;
    }
    if(indx >= nums.size() || target < 0 ) return;
    //picking
    if(target >= nums[indx]){
        ds.push_back(nums[indx]);
        comb_sum_II(indx+1,target-nums[indx],nums,ds,ans);
        ds.pop_back();
    }
    //not picking
    // Skip duplicates for the "not picking" branch
    int next_indx = indx + 1;
    while(next_indx < nums.size() && nums[next_indx] == nums[indx]) {
            next_indx++;
    }
    comb_sum_II(next_indx,target,nums,ds,ans);
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
