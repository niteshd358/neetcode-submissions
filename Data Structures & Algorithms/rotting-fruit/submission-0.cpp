class Solution {
    int n, m ;
public:
    int orangesRotting(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        queue<pair<int,int>> q;
        
        for(int i=0; i<n; ++i){
            for(int j=0; j<m; ++j){
                if(grid[i][j] == 2){
                    q.push({i,j});
                }
            }
        }

        int time = 0;
        bool rotten_now = false;
        int dr[] = {1,0,-1,0};
        int dc[] = {0,1,0,-1};

        while(!q.empty()){
            int size = q.size();

            for(int i=0; i<size; ++i){
                auto [r,c] = q.front();
                q.pop();

                for(int i=0; i<4; ++i){
                    int row = r + dr[i];
                    int col = c + dc[i];

                    if(row<0 || row>=n || col<0 || col>=m){
                        continue;
                    }

                    if(grid[row][col] == 1){
                        grid[row][col] = 2;
                        q.push({row,col});
                        rotten_now = true;
                    }
                }
            }
            if(rotten_now){
                time++;
            }
            rotten_now = false;
        }

        for(int i=0; i<n; ++i){
            for(int j=0; j<m; ++j){
                if(grid[i][j] == 1){
                    return -1;
                }
            }
        }
        return time;
    }
};

