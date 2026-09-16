class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        int cols = matrix[0].size();

        int left = 0 , right = rows * cols - 1;

        while(left <= right){
            int mid = left + (right - left) /2;
            int r = mid / cols ;
            int c = mid % cols ;
            if(target > matrix[r][c]){
                left = mid + 1;
            }
            else if (target < matrix[r][c]){
                right = mid - 1;
            }
            else{
                return true;
            }
        }
        return false;
    }
};
