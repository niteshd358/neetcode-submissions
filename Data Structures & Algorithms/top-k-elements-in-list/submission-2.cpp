class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> count;
        for(int i = 0 ; i <nums.size() ; ++i){
            count[nums[i]]++;
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> minHeap;
        for(auto &entry : count){
            minHeap.push({entry.second,entry.first});
            if(minHeap.size() > k) minHeap.pop();
        }
        vector<int> result;
        while(minHeap.size()){
            result.push_back(minHeap.top().second);
            minHeap.pop();
        }
        return result;
    }
};
