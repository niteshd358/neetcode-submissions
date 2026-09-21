class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n = s.length();
        unordered_map<char,int> lastIndex;
        for(int i=0; i<n; ++i){
            lastIndex[s[i]] = i;
        }
        vector<int> ans;
        int size = 0, end = 0;
        for(int i=0; i<n; ++i){
            size++;
            end = max(end,lastIndex[s[i]]);

            if(i == end){
                ans.push_back(size);
                size = 0;
            }
        }
        return ans;
    }
};
