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

        if(s[i] == '0') return;

        // take one digit
        count(i+1,s,cnt);

        // tae two digits
        if(i+1 < s.length()) {
            if(s[i]=='1' || (s[i]=='2') && (s[i+1] <= '6')){
                 count(i+2,s,cnt);
            }
        }
    }
};
