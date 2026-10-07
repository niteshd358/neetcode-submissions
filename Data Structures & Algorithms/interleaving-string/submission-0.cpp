class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if(s3.size() != s1.size()+s2.size()) return false;

        return dfs(0,0,0,s1,s2,s3);

    }

    bool dfs(int i, int j, int k, string &s1, string &s2, string &s3){
        if(k >= s3.size()) return true;

        bool s1sub = (s3[k] == s1[i]) ? dfs(i+1,j,k+1,s1,s2,s3) : false;
        bool s2sub = (s3[k] == s2[j]) ? dfs(i,j+1,k+1,s1,s2,s3) : false;

        return s1sub || s2sub ;
    }
};
