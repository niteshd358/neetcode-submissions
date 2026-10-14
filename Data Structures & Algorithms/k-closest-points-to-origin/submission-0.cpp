class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>> minHeap;
        for(int i=0; i<points.size(); ++i){
            int dist = abs(points[i][0]) + abs(points[i][1]);
            minHeap.push({dist,i});
        }
        vector<vector<int>> result;
        while(result.size() < k){
            result.push_back(points[minHeap.top().second]);
            minHeap.pop();
        }
        return result;
    }
};
