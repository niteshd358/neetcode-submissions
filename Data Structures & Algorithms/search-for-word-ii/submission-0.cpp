class Solution {
    int rows, cols;
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        rows = board.size();
        cols = board[0].size();

        vector<string> result;

        for(string &word : words){
            bool flag = false;
            for(int r=0; r<rows && !flag; ++r){
                for(int c=0; c<cols; ++c){
                    if(board[r][c] != word[0]) continue;
                    if(backtrack(board,r,c,word,0)){
                        result.push_back(word);
                        flag = true;
                        break;
                    }
                }
            }
        }
        return result;
    }

    bool backtrack(vector<vector<char>>& board, int r, int c, string& word, int i){
        if(i == word.length()) return true;
        if(r<0 || r>=rows || c<0 || c>=cols || board[r][c] != word[i]){
            return false;
        }

        board[r][c] = '*';
        bool ret =  backtrack(board, r+1, c, word, i+1) || 
                    backtrack(board, r-1, c, word, i+1) ||
                    backtrack(board, r, c+1, word, i+1) ||
                    backtrack(board, r, c-1, word, i+1);
        
        board[r][c] = word[i];
        return ret;
    }
};
