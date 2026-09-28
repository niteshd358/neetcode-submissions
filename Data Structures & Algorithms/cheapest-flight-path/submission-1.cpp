class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>>adj(n);
        for(auto edge : flights){
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];
            adj[u].push_back({v,wt});
        }
        vector<int> distance(n,INT_MAX);
        priority_queue<array<int,3>, vector<array<int,3>>, greater<>> pq; // dist, node, k
        pq.push({0,src,k});\
        distance[src] = 0;
        while(!pq.empty()){
            auto [currDist, node, leftK] = pq.top();
            pq.pop();
            if(leftK < 0 ) continue;
            for(auto it : adj[node]){
                auto [v,wt] = it;
                if(distance[v] > currDist+wt) {
                    distance[v] = currDist+wt;
                    pq.push({currDist+wt,v,leftK-1});
                }
            }
        }
        return distance[dst] == INT_MAX ? -1 : distance[dst];
    }
};
