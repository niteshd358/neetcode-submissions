class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> indegrees(numCourses);
        for(auto &edge: prerequisites){
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            indegrees[v]++;
        }

        queue<int>q;
        for(int i=0; i<numCourses; ++i){
            if(indegrees[i] == 0) q.push(i);
        }
        //kahn's algo bfs
        int finish = 0;
        while(!q.empty()){
            int top = q.front();
            q.pop();
            finish++;
            for(auto &neighbor:adj[top]){
                indegrees[neighbor]--;
                if(indegrees[neighbor] == 0) q.push(neighbor);
            }
        }
        return finish == numCourses;
    }
};
