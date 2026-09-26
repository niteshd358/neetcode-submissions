class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> indegrees(numCourses);
        vector<int> result;
        for(auto &edge: prerequisites){
            int u = edge[0];
            int v = edge[1];
            adj[v].push_back(u);
            indegrees[u]++;
        }
        queue<int> q;
        for(int i=0; i<numCourses; ++i){
            if(indegrees[i]==0) q.push(i);
        }

        while(!q.empty()){
            int node = q.front();
            q.pop();
            result.push_back(node);
            for(auto &neighbor : adj[node]){
                indegrees[neighbor]--;
                if(indegrees[neighbor]==0) q.push(neighbor);
            }
        }
        return result;
    }
};
