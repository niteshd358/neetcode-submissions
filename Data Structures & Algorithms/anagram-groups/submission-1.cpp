class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;
        int n = strs.size();
        unordered_map<string,vector<string>> mpp;
        for(int i=0; i<n; ++i){
            string sorted1 = strs[i];
            sort(sorted1.begin(),sorted1.end());
            mpp[sorted1].push_back(strs[i]);
        }
        for(auto &substr : mpp){
            result.push_back(substr.second);
        }
        return result;
    }
};
