class Solution {
    vector<vector<int>>dp;
public:
    int numDistinct(string s, string t) {
        if(s.size() < t.size()) return 0;
        dp.assign(s.size(), vector<int>(t.size(),-1));
        return dfs(0,0,s,t);
    }

    int dfs(int i, int j, string &s, string &t){
        if(j == t.size()) return 1;
        if(i == s.size()) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        //take only if matches
        int take = 0;
        if(s[i]==t[j]) take = dfs(i+1,j+1,s,t);

        // notae
        int notake = dfs(i+1,j,s,t);

        return dp[i][j] = take + notake;
    }
};
