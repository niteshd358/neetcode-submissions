class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> mpp;
        int res =0 ;

        for(int num : nums){
            if(!mpp[num]){
                mpp[num] = mpp[num-1] + mpp[num+1] + 1;
                mpp[num - mpp[num-1]] = mpp[num];
                mpp[num + mpp[num+1]] = mpp[num];
            }
            res = max(res, mpp[num]);
        }
        
        return res;
    }
};
