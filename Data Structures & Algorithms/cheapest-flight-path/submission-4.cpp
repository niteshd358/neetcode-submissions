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
        queue<tuple<int,int,int>> q; // {stops, node, wt}
        vector<int> distance(n,INT_MAX);
        
        distance[src] = 0;
        q.push({0,src,0});
        

        while(!q.empty()){
            auto [stops, node, cost] = q.front();
            q.pop();
            if(stops > k) continue;
            for(auto &[next,wt] : adj[node]){
                int newDist = cost + wt;
                if(newDist < distance[next]){
                    distance[next] = newDist;
                    q.push({stops+1,next,newDist});
                }
            }
        }
        return distance[dst] == INT_MAX ? -1 : distance[dst];
    }
};
