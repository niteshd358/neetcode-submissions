class Solution {
    void subsetII(int indx, vector<int>&nums, vector<int>&ds,vector<vector<int>>&ans){
        
            ans.push_back(ds);
        
        for(int i = indx ; i <nums.size() ; ++i){
            if(i>indx && nums[i] == nums[i-1]) continue;

            ds.push_back(nums[i]);
            subsetII(i+1,nums,ds,ans);
            ds.pop_back();
        }        
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        ans.reserve(1<<nums.size());
        vector<int> ds;
        ds.reserve(nums.size());
        sort(nums.begin(),nums.end());
        subsetII(0,nums,ds,ans);
        return ans;
    }
};
