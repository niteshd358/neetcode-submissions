class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;
        int n = strs.size();
        unordered_map<string,vector<string>> mpp;
        for(const auto& s : strs){
            vector<int> count(26,0);
            for(char c : s){
                count[c-'a']++;
            }
            string key = to_string(count[0]);
            for(int i=1 ; i<26 ; ++i){
                key = key + ',' + to_string(count[i]);
            }
            mpp[key].push_back(s);
        }
        for(const auto &pair : mpp){
            result.push_back(pair.second);
        }
        return result;
    }
};
