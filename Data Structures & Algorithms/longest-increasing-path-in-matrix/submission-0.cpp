class Solution {
    int m,n;
    vector<vector<int>>dp;
    vector<vector<int>>directions = {{0,1},{1,0},{0,-1},{-1,0}};

public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        m = matrix.size();
        n = matrix[0].size();

        dp.assign(m,vector<int>(n,-1));

        int longest = 0;

        for(int i=0; i<m; ++i){
            for(int j=0; j<n; ++j){
                longest = max(longest,dfs(i,j,matrix,INT_MIN)); 
            }
        }
        return longest;
    }

    int dfs(int i, int j, vector<vector<int>>& matrix, int preVal){
        if(i < 0 || i >= m || j < 0 || j >= n || matrix[i][j] <= preVal){
            return 0;
        }

        if(dp[i][j] != -1) return dp[i][j];

        int res = 1;

        for(auto &d : directions){
            res = max(res, 1+ dfs(i+d[0],j+d[1],matrix,matrix[i][j]));
        }
        return dp[i][j] = res;
    }
};
