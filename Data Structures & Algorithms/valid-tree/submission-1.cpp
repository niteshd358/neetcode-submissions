class Solution {
private:
    bool dfs(int node, int parent, vector<vector<int>>&adj, vector<bool>&visited){
        visited[node] = true;
        for(auto &neighbor:adj[node]){
            // Ignore the edge back to parent
            if(neighbor == parent) continue;
            // Already visited -> cycle
            if(visited[neighbor]) return false;
            // DFS into unvisited neighbor
            if(!dfs(neighbor, node, adj, visited))
                return false;
        }
        return true;
    }
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adj(n);
        for(auto &edge:edges){
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<bool> visited(n,false);
        int parent = -1;
        // Start DFS from node 0
        if(!dfs(0, -1, adj, visited)) return false;

        // Check connectivity
        for(int i=0; i<n; ++i){
            if(!visited[i]){
                return false;
            }
        }
        return true;
    }
};
