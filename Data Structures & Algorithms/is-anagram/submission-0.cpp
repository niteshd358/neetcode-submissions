class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()) return false;
        vector<int> hash(26,0);
        for(int i = 0 ; i < s.length() ; i++){
            hash[s[i] - 'a']++;
        }
        for(int i = 0 ; i < t.length() ; i++){
            if(hash[t[i] - 'a'] == 0) return false;
            hash[t[i]-'a']--;
        }
        return true;
    }
};
