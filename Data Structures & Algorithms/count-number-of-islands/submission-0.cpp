class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> vis(n,vector<bool>(m,false));
        int count  =0;
        for(int i = 0 ; i< n; ++i){
            for(int j = 0; j <m ; j++){
                if(!vis[i][j]){
                    if(grid[i][j] == '1'){
                        count++;
                        dfs(i,j,grid,vis);
                    }
                }
            }
        }
        return count;
    }
    void dfs(int r, int c, vector<vector<char>>&grid,vector<vector<bool>>&vis){
        vis[r][c] = true;
        int dr[] = {1, 0 , -1, 0};
        int dc[] = {0, 1, 0, -1};
        for(int i=0; i<4; i++){
            int row = r + dr[i];
            int col = c + dc[i];
            if(row<0 || row >= grid.size() || col <0 || col>=grid[0].size() ) continue;
            if(!vis[row][col] && grid[row][col] == '1'){
                dfs(row,col,grid,vis);
            }
        }
    }
};
