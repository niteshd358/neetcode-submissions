class Solution {
public:
    int maxArea(vector<int>& heights) {
        int maxArea = 0;
        int left = 0 , right = heights.size()-1;
        while(left < right){
            int area = min(heights[left],heights[right]) * (right-left);
            maxArea = max(maxArea,area);
            heights[left] < heights[right] ? left ++ : right--;
        }

        return maxArea;
    }
};
