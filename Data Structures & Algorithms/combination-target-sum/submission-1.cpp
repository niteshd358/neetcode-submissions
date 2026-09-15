class Solution {
void comb_sum(int start, int target,vector<int> & nums, vector<vector<int>> & ans, vector<int>& ds){
    
    if(target == 0){
        ans.push_back(ds);
        return;
    }
    for(int i=start; i<nums.size(); i++){
        if(nums[i] > target) break;
        ds.push_back(nums[i]);
        comb_sum(i,target-nums[i],nums,ans,ds);
        ds.pop_back();
    }
}
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        vector<int>ds;
        sort(nums.begin(),nums.end());
        comb_sum(0,target,nums,ans,ds);
        return ans;
    }
};
