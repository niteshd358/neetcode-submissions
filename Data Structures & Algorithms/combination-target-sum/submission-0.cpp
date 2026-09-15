class Solution {
void comb_sum(int indx, int target,vector<int> & nums, vector<vector<int>> & ans, vector<int>& ds){
    
    if(target == 0){
        ans.push_back(ds);
        return;
    }
    if(indx == nums.size() || target < 0) return;


    //PICK
    if(target >= nums[indx]){
        ds.push_back(nums[indx]);
        comb_sum(indx, target - nums[indx],nums,ans,ds);
        ds.pop_back();
    }
    //NOT PICK
    comb_sum(indx+1, target,nums,ans,ds);
}
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        vector<int>ds;
        comb_sum(0,target,nums,ans,ds);
        return ans;
    }
};
