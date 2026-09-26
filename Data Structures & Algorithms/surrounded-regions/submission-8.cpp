// ["X","O","X","O","X","O"],
// ["O","X","O","X","O","X"],
// ["X","O","X","O","X","O"],
// ["O","X","O","X","O","X"]

class Solution {
private:
    void dfs(int r, int c, int n, int m,vector<vector<char>>&board){
        board[r][c] = 'V';
        int dr[] = {1,0,-1,0};
        int dc[] = {0,1,0,-1};
        for(int i=0; i<4; ++i){
            int row = r + dr[i];
            int col = c + dc[i];
            if(isSafe(row,col,n,m) && board[row][col] == 'O'){
                dfs(row,col,n,m,board);
            }
        }
    }

    bool isSafe(int r, int c, int n, int m){
        return (r>=0 && r<n && c>=0 && c<m);
    }

public:
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();

        // mark all Os connecting to border Os as V (beacusse they will not change)
        for(int i=0; i<m; ++i){
            if(board[0][i]=='O')dfs(0,i,n,m,board);  // 1st row
            if(board[n-1][i]=='O')dfs(n-1,i,n,m,board);// last row
        }
        for(int j=0; j<n; ++j){
            if(board[j][0]=='O')dfs(j,0,n,m,board);  // 1st col
            if(board[j][m-1]=='O')dfs(j,m-1,n,m,board);// last col
        }
        // traversew whole matrix and if 
        for(int i=0; i<n; ++i){
            for(int j=0; j<m; ++j){
                if(board[i][j]=='O'){
                    board[i][j] = 'X';
                }
                else if(board[i][j]=='V'){
                    // mark all Vs  back to O
                    board[i][j] = 'O';
                }
            }
        }
    }
};
