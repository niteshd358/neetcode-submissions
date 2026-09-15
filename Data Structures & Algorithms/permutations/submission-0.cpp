class Solution {
    void solve (int leftIndx , vector<int>&nums, vector<vector<int>>&ans, int n){
        if(leftIndx >= n-1) {
            ans.push_back(nums);
            return;
        }
        for(int i=leftIndx; i<nums.size() ; i++){
            swap(nums[leftIndx],nums[i]);
            solve(leftIndx+1,nums,ans,n);
            swap(nums[leftIndx],nums[i]);
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        solve(0,nums,ans,n);
        return ans;
    }
};
