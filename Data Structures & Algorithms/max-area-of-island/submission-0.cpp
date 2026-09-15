class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<bool>> vis(n,vector<bool>(m,false));

        int count = 0;
        int maxArea = 0;
        int area= 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m ; j++){
                if(!vis[i][j]){
                    if(grid[i][j] == 1){
                        count++;
                        maxArea = max(maxArea,area);
                        area = 0;
                        dfs(i,j,grid,vis,area);
                    }
                }
            }
        }
        return maxArea;
    }
    void dfs(int r, int c, vector<vector<int>>&grid, vector<vector<bool>>&vis,int &area){
        vis[r][c] = true;
        area++;
        int dr[] = {1,0,-1,0};
        int dc[] = {0,1,0,-1};
        for(int i=0; i<4; i++){
            int row = r + dr[i];
            int col = c + dc[i];
            if(row<0 || row>=grid.size() || col <0 || col>=grid[0].size()) continue;
            if(!vis[row][col] && grid[row][col] == 1)
            dfs(row,col,grid,vis,area);
        }
    }
};
