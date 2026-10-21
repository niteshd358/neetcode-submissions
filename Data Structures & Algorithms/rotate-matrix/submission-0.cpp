class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        // first Traspose then reverse each row
        // 1 3  ->    3 1
        // 2 4  ->    4 2

        int n = matrix.size();
        // Transpose
        for(int i=0; i<n; ++i){
            for(int j=i; j<n; ++j){
                swap(matrix[i][j],matrix[j][i]);
            }
        }

        // Reverse Each rows
        for(int i=0; i<n; i++){
            for(int j = 0; j<n/2; ++j){
                swap(matrix[i][j],matrix[i][n-1-j]);
            }
        }
       
    }
};
