class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        //adjList
        vector<vector<pair<int,int>>> adj(n+1);
        for(int i=0; i<times.size(); ++i){
            int u = times[i][0];
            int v = times[i][1];
            int w = times[i][2];
            adj[u].push_back({v,w});
        }

        // shortest path Dijkstra
        //minheap to get shortest time {distacneFromSRC,node}
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>> minHeap;

        vector<int>dist(n+1,INT_MAX);

        dist[k] = 0;
        minHeap.push({0,k});
        
        int shortest_path = 0;
        vector<bool>visited(n,false);
        while(!minHeap.empty()){
            auto [currDist, node] = minHeap.top();
            minHeap.pop();
            
            // Ignore outdated heap entry
            if(currDist > dist[node]) continue;

            for(auto [nextNode, weight] : adj[node]){
               int newDist = currDist + weight;

               if(newDist < dist[nextNode]){
                    dist[nextNode] = newDist;
                    minHeap.push({newDist,nextNode});
               }
            }
        }

        int ans = 0;
        for(int i = 1 ; i<=n ; ++i){
            if(dist[i] == INT_MAX) return -1;
            ans = max(ans,dist[i]);
        }
        return ans;
    }
};
