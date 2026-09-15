class Solution {
    void subset(int indx, vector<int> ds, vector<vector<int>> &ans,vector<int> &nums){
        if(indx == nums.size()) {
            ans.push_back(ds);
            return;
        }
        ds.push_back(nums[indx]);
        subset(indx+1,ds,ans,nums);
        ds.pop_back();
        subset(indx+1,ds,ans,nums);
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> ds;
        int indx = 0;
        subset(0,ds,ans,nums);
        return ans;
    }
};
