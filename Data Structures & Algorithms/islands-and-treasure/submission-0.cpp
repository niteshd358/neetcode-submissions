class Solution {
    int n,m;
    
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();

        queue<pair<int,int>> q;

        //put all gates into queue
        for(int i=0; i<n; ++i){
            for(int j=0; j<m; ++j){
                if(grid[i][j] == 0){
                    q.push({i,j});
                }
            }
        }

        int dr[] = {1,0,-1,0};
        int dc[] = {0,1,0,-1};

        while(!q.empty()){
            auto [r,c] = q.front();
            q.pop();
            
            for(int i=0; i<4; ++i){
                int row = r + dr[i];
                int col = c + dc[i];
                // Out of bounds or wall
                if(row<0 || row>=n || col<0 || col>=m || grid[row][col] == -1) continue;
                // Already processed / has a shorter distance
                if(grid[row][col] != INT_MAX){
                    continue;
                }
                grid[row][col] = grid[r][c]+1;

                q.push({row,col});
            }
        }

    }

    void dfs(int r, int c, vector<vector<int>>& grid, vector<vector<bool>>&visited){
        visited[r][c] = true;
        
        
    }
};
