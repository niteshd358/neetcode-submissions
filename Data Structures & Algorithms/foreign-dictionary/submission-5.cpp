class Solution {
private:
    vector<int> toposort(int n, vector<vector<int>>&adj){
        vector<int>indegrees(n,0);
        vector<int> result;
        for(int i=0; i<n; i++){
            for(auto it : adj[i]){
                indegrees[it]++;
            }
        }

        queue<int>q;
        for(int i=0; i<n; ++i){
            if(indegrees[i]==0) q.push(i);
        }

        while(!q.empty()){
            int node = q.front();
            q.pop();
            result.push_back(node);
            for(auto it : adj[node]){
                indegrees[it]--;
                if(indegrees[it] == 0) q.push(it);
            }
        }
        return result.size() == n ? result : vector<int>{};
    }
public:
    string foreignDictionary(vector<string>& words) {
        vector<vector<int>>adj(26);
        vector<bool> present(26,false);
        for(int i=0; i<words.size(); ++i){
            for(char c : words[i]){
                present[c-'a'] = true;
            }
        }
        //bild the Directed graph
        for(int i=1; i<words.size();++i){
            string s1 = words[i-1];
            string s2 = words[i];
            int len = min(s1.length(),s2.length());
            bool foundDifference = false;
            for(int j=0; j<len; ++j){
                if(s1[j] != s2[j]){
                    adj[s1[j]-'a'].push_back(s2[j]-'a');
                    foundDifference = true;
                    break;
                }
            }
            
            if(!foundDifference && s1.size() > s2.size()){
                // here abc -> come before ab
                return "";
            }
        }

        vector<int> result = toposort(26,adj);

        string finalResult = "";

        for(auto it : result){
            if(present[it]){
                finalResult += char(it + 'a');
            }
        }
        return finalResult;
    }
};
