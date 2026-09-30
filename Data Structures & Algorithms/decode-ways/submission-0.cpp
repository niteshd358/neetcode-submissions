class Solution {
public:
    int numDecodings(string s) {
        int cnt = 0;
        count(0,s,cnt);
        return cnt;
    }
    void count(int i, string &s, int& cnt){
        if(i == s.length()) {
            cnt++;
            return;
        }
        if(i>s.length()) return;
        if(s[i] == '0') return;
        count(i+1,s,cnt);
        count(i+2,s,cnt);
    }
};
