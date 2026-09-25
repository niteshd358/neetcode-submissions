class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        int area = 0;

        // for width find Next Smaller elemt and prev smaller ele index
        vector<int>nse(n,0); 
        vector<int>pse(n,0);
        stack<int> s;

        //Next smaller Element
        for(int i=n-1; i>=0; --i){
            while(!s.empty() && heights[s.top()] >= heights[i]){
                s.pop();
            }
            nse[i] = s.empty() ? n : s.top();
            s.push(i);
        }

        while(!s.empty()){
            s.pop();
        }
        //prev smaller Element
        for(int i=0; i<n; ++i){
            while(!s.empty() && heights[s.top()] >= heights[i]){
                s.pop();
            }
            pse[i] = s.empty() ? -1 : s.top();
            s.push(i);
        }

        for(int i = 0; i<n; i++){
            // width = (nse - pse - 1)
            int width = nse[i] - pse[i] - 1;
            int area_with_curr_ind = heights[i] * width ;
            area = max(area, area_with_curr_ind);
        }
        return area;
    }
};
