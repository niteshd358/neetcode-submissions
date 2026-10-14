class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int,int>> maxHeap;
        for(int i=0; i<points.size(); ++i){
            int dist = pow(points[i][0],2) + pow(points[i][1],2);
            maxHeap.push({dist,i});
            if(maxHeap.size() > k){
                maxHeap.pop();
            }
        }
        vector<vector<int>> result;
        while(maxHeap.size()){
            result.push_back(points[maxHeap.top().second]);
            maxHeap.pop();
        }
        return result;
    }
};
