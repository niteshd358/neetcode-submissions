class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        
        sort(nums.begin(),nums.end());

        do{
            ans.push_back(nums);
        }while(next_permutation(nums.begin(),nums.end()));

        return ans;
    }



//     void solve (int leftIndx , vector<int>&nums, vector<vector<int>>&ans){
//         if(leftIndx >= nums.size()-1) {
//             ans.push_back(nums);
//             return;
//         }
//         for(int i=leftIndx; i<nums.size() ; i++){
//             swap(nums[leftIndx],nums[i]);
//             solve(leftIndx+1,nums,ans);
//             swap(nums[leftIndx],nums[i]);
//         }
//     }
// public:
//     vector<vector<int>> permute(vector<int>& nums) {
//         vector<vector<int>> ans;
//         solve(0,nums,ans);
//         return ans;
//     }
};
