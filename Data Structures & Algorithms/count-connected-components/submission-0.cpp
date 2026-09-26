class Solution {
private:
    void dfs(int node, vector<vector<int>> &adj, vector<bool> &vis){
        vis[node] = true;
        for(auto &neighbor : adj[node]){
            if(!vis[neighbor]){
                dfs(neighbor,adj,vis);
            }
        }
    }
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for(auto &edge : edges){
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
        }
        int count = 0;
        vector<bool> vis(n,false);
        for(int i=0; i<n; ++i){
            if(!vis[i]){
                count++;
                dfs(i,adj,vis);
            }
        }
        return count;
    }
};
