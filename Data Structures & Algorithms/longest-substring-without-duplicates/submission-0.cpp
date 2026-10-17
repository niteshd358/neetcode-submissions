class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int>freq(256,-1);
        int l=0, cnt = 0;
        for(int r=0; r<s.size(); ++r){
            if(freq[s[r]] != -1){
                l = max(l, freq[s[r]] + 1);
            }
            freq[s[r]] = r;
            cnt = max(cnt, r-l+1);
        }
        return cnt;
    }
};
