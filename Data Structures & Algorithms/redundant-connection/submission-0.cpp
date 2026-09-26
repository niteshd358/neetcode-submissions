class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        unordered_map<int,int> mp;
        for(auto &edge:edges){
            int u = edge[0];
            int v = edge[1];
            if(mp.find(u) != mp.end() && mp.find(v) != mp.end()) return {u,v};
            if(mp.find(u) == mp.end()) mp[u]++;
            if(mp.find(v) == mp.end()) mp[v]++;
        }
    }
};
