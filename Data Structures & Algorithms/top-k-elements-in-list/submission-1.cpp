class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> result;
        unordered_map<int,int> mpp;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> minHeap;
        for(int i = 0 ; i <nums.size() ; ++i){
            mpp[nums[i]]++;
        }
        for(const auto &freq : mpp){
            minHeap.push({freq.second,freq.first});
            if(minHeap.size() > k) minHeap.pop();
        }
        while(minHeap.size()){
            pair<int,int> freq_element = minHeap.top();
            minHeap.pop();
            result.push_back(freq_element.second);
        }
        return result;
    }
};
