class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        int node = 0;
        vector<int> dist(n,INT_MAX);
        vector<bool> visited(n,false);
        int edges = 0, res = 0; // total  min edges == n-1
        while(edges < n-1){
            visited[node] = true;
            int nextNode = -1;
            for(int i=0; i<n; ++i){
                if(!visited[i]){
                    int currDist = abs(points[i][0]-points[node][0]) + abs(points[i][1]-points[node][1]);
                    dist[i] = min(dist[i],currDist);
                    if(nextNode == -1 || dist[i] < dist[nextNode]){
                        nextNode = i;
                    }
                }
            }
            res += dist[nextNode];
            node = nextNode;
            edges++;
        }
        return res;
    }
};
