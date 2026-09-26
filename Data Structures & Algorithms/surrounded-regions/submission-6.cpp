["X","O","X","O","X","O"],
["O","X","O","X","O","X"],
["X","O","X","O","X","O"],["O","X","O","X","O","X"]]

class Solution {
private:
    void dfs(int r, int c, int n, vector<vector<char>>&board){
        board[r][c] = 'V';
        int dr[] = {1,0,-1,0};
        int dc[] = {0,1,0,-1};
        for(int i=0; i<4; ++i){
            int row = r + dr[i];
            int col = c + dc[i];
            if(isSafe(row,col,n) && board[row][col] == 'O'){
                dfs(row,col,n,board);
            }
        }
    }

    bool isSafe(int r, int c, int n){
        return (r>=0 && r<n && c>=0 && c<n);
    }

public:
    void solve(vector<vector<char>>& board) {
        int n = board.size();

        // mark all Os connecting to border Os as V (beacusse they will not change)
        for(int i=0; i<n; ++i){
            if(board[0][i]=='O')dfs(0,i,n,board);  // 1st row
            if(board[n-1][i]=='O')dfs(n-1,i,n,board);// last row
            if(board[i][0]=='O')dfs(i,0,n,board);  // 1st col
            if(board[i][n-1]=='O')dfs(i,n-1,n,board);// last col
        }
        // traversew whole matrix and if 
        for(int i=0; i<n; ++i){
            for(int j=0; j<n; ++j){
                if(board[i][j]=='O'){
                    board[i][j] = 'X';
                }
                // mark all Vs  back to O
                if(board[i][j]=='V'){
                    board[i][j] = 'O';
                }
            }
        }
    }
};
