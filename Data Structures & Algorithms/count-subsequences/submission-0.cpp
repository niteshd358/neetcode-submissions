class Solution {
public:
    int numDistinct(string s, string t) {
        if(s.size() < t.size()) return 0;
        return dfs(0,0,s,t);
    }

    int dfs(int i, int j, string &s, string &t){
        if(j == t.size()) return 1;
        if(i == s.size()) return 0;

        // int res = dfs(i+1, j, s,t);

        //take
        int take = 0;

        if(s[i]==t[j]) take = dfs(i+1,j+1,s,t);

        // notae
        int notake = dfs(i+1,j,s,t);

        return take + notake;
    }
};
