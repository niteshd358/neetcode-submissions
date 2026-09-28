class Solution {
private:
    bool isSafe(int r, int c, int n){
        return (r>=0 && r<n && c>=0 & c<n);
    }
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        priority_queue<array<int, 3>,vector<array<int, 3>>,greater<>> pq;
        vector<vector<bool>> visited(n, vector<bool>(n, false));

        // pq stores {max_elevation_so_far, row, col}
        pq.push({grid[0][0],0,0});
        visited[0][0] = true;

        int dr[] = {1,0,-1,0};
        int dc[] = {0,1,0,-1};

        while(!pq.empty()){
            auto [t, r, c] = pq.top();
            pq.pop();
            if(r == n-1 && c== n-1) return t;
            for(int i=0; i<4; i++){
                int row = r + dr[i];
                int col = c + dc[i];
                if(isSafe(row,col,n) && !visited[row][col]){
                    visited[row][col] = true;
                    pq.push({max(t,grid[row][col]),row,col});
                }
            }
        }
        return 0;
    }
};
