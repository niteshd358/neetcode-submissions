class Solution {
private: 
    vector<int> toposort(int n, vector<vector<int>>&adj){
        vector<int> indegrees(n,0);
        for(int i=0; i<n; ++i){
            for(auto it : adj[i]){
                indegrees[it]++;
            }
        }
        queue<int>q;
        for(int i=0; i<n; ++i){
            if(indegrees[i]==0){
                q.push(i);
            }
        }
        vector<int> result;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            result.push_back(node);
            for(auto it : adj[node]){
                indegrees[it]--;
                if(indegrees[it]==0) q.push(it);
            }
        }
        return result;
    }
public:
    string foreignDictionary(vector<string>& words) {
        
        vector<vector<int>>adj(26); //lower case english letters
        // Track characters that actually occur
        vector<bool> present(26, false);
        for (auto& word : words) {
            for (char c : word) {
                present[c - 'a'] = true;
            }
        }
        //create a Directed Graph (adj)
        for(int i=1; i<words.size(); ++i){
            string s1 = words[i-1];
            string s2 = words[i];
            int len = min(s1.length(),s2.length());
            bool foundDifference = false;
            for(int j=0; j<len; ++j){
                if(s1[j] != s2[j]){
                    // s1 = bbc; s2= abd --> b comes before a i.e b->a
                    adj[s1[j]-'a'].push_back(s2[j]-'a');
                    foundDifference = true;
                    break;
                }
            }
            // Invalid case:
            // "abc" cannot come before "ab"
            if (!foundDifference && s1.size() > s2.size()) {
                return "";
            }
        }

        //created an adjanceny list 
        vector<int> result = toposort(26,adj);
        // Count characters actually present
        int totalChars = 0;

        for (int i = 0; i < 26; ++i) {
            if (present[i]) {
                totalChars++;
            }
        }
        // Cycle exists
        // if (result.size() < totalChars) {
        //     return "";
        // }

        string finalresult = "";

        for (int node : result) {
            if (present[node]) {
                finalresult += char(node + 'a');
            }
        }
        return finalresult;

    }
};
