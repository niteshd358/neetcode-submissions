class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int top = 0, bot = matrix.size()-1;
        int midRow;
        while(top<=bot){
            midRow = top + (bot - top) / 2;
            if(matrix[midRow][0] > target){
                bot = midRow -1;
            }
            else if (matrix[midRow][0] < target){
                top = midRow +1;
            }
            else{
                return true;
            }
        }

        int left = 0 , right = matrix[0].size()-1;
        while(left<=right){
            int mid = left + (right - left) /2 ;
            if(matrix[midRow][mid] > target){
                right = mid - 1;
            }
            else if (matrix[midRow][mid] < target){
                left = mid + 1;
            }
            else{
                return true;
            }
        }
        return false;
    }
};
