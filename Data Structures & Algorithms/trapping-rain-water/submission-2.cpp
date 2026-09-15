class Solution {
struct ElementBounds {
    int max_left = 0;
    int max_right = 0;
};
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<ElementBounds> bounds(n);

        for(int i=1; i<n; i++){
            bounds[i].max_left = max(bounds[i-1].max_left,height[i-1]);
        }
        for(int i=n-2 ;i>=0; --i){
            bounds[i].max_right = max(bounds[i+1].max_right,height[i+1]);
        }
        int total_trap = 0;
        for(int i = 1 ; i < n - 1 ; ++i){
            if(height[i] < bounds[i].max_left && height[i] < bounds[i].max_right){
                int trap_at_curr_pos = min(bounds[i].max_left,bounds[i].max_right) - height[i];
                total_trap += trap_at_curr_pos;
            }
        }
        return total_trap;
    }
};
