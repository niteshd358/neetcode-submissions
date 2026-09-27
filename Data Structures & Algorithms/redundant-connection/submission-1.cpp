class DisjointSetUnion {
public:
    vector<int> parent,rank;

    DisjointSetUnion(int n){
        rank.resize(n,1);
        parent.resize(n);
        for(int i=0; i<n; ++i){
            parent[i]=i;
        }
    }
    int Find_par(int i){
        if(parent[i]==i) return i;
        return parent[i] = Find_par(parent[i]);
    }
    void Union(int a, int b){
        int p1 = Find_par(a);
        int p2 = Find_par(b);
        if(p1 == p2) return;
        if(rank[p1] > rank[p2]){
            parent[p2] = p1;
            rank[p1] += rank[p2];
        }else{
            parent[p1] = p2;
            rank[p2] += rank[p1];
        }
    }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();

        DisjointSetUnion dsu(n+1);

        for(auto &edge:edges){
            int u = edge[0];
            int v = edge[1];
            
            if(dsu.Find_par(u) == dsu.Find_par(v)){
                return {u,v};
            }
            dsu.Union(u,v);
        }
        return {};        
    }
};
