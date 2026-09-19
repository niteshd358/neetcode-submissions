class Solution {
private:
    // Graph where destinations sorted lexicograpihcally (minHeap) --> like adjList
    unordered_map<string,priority_queue<string, vector<string> , greater<string>>> adjMap;
    // result itinerary
    vector<string> result;

    void dfs(string airport){
        result.push_back(airport);
        //while there are available flights out of this airport
        while(!adjMap[airport].empty()){
            string next_stop = adjMap[airport].top();
            adjMap[airport].pop(); // burn the ticket after usage
            dfs(next_stop);
        }

    }

public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {

        for(int i=0; i<tickets.size(); ++i){
            string u = tickets[i][0];
            string v = tickets[i][1];
            adjMap[u].push(v);
        }

        // Start DFS from the mandatory starting point "JFK"
        dfs("JFK");

        return result;
    }
};
