class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>>adj(n);
        for(auto &edge : flights){
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];
            adj[u].push_back({v,wt});
        }
        // distance[node][edges] = minimum cost to reach node
        // using exactly 'edges' flights
        vector<vector<int>> distance(n,vector<int>(k+2, INT_MAX));
        
        priority_queue<array<int,3>, vector<array<int,3>>, greater<>> pq; // {cost, node, edges_used}

        distance[src][0] = 0;

        pq.push({0,src,0});
        while(!pq.empty()){
            auto [currCost, node, edgeUsed] = pq.top();
            pq.pop();
            
            if(node == dst) return currCost;

            if(edgeUsed >= k + 1 ) continue;

            for(auto &[next,wt] : adj[node]){
                int newCost = currCost + wt;
                int newEdge = edgeUsed + 1;
                if(distance[next][newEdge] > newCost) {
                    distance[next][newEdge] = newCost;
                    pq.push({newCost,next,newEdge});
                }
            }
        }
        return -1;
    }
};
