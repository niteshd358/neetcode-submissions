class Solution {
    int n, m;
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        n = heights.size();
        m = heights[0].size();
        
        vector<vector<int>> res;

        vector<vector<bool>> pacific(n, vector<bool>(m, false));
        vector<vector<bool>> atlantic(n, vector<bool>(m, false));

        for(int i=0; i<n; ++i) dfs(i,0,heights,pacific);
        for(int j=0; j<m; ++j) dfs(0,j,heights,pacific);

        for(int i=0; i<n; ++i) dfs(i,m-1,heights,atlantic);
        for(int j=0; j<m; ++j) dfs(n-1,j,heights,atlantic);

        for(int i=0; i<n; ++i){
            for(int j=0; j<m; ++j){
                if(pacific[i][j] && atlantic[i][j]){
                    res.push_back({i,j});
                }
            }
        }
        return res;
    }

    void dfs(int r, int c, vector<vector<int>>& heights, vector<vector<bool>>& visited){
        visited[r][c] = true;
        int dr[] = {0,1,0,-1};
        int dc[] = {1,0,-1,0};

        for(int i=0; i<4; ++i){
            int row = r + dr[i];
            int col = c + dc[i];
            if(row<0 || row>=n || col<0 || col>=m) continue;
            if(!visited[row][col] && heights[row][col] >= heights[r][c]){
                dfs(row,col,heights,visited);
            }
        }
    }
};
