class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> maxHeap;
        for(int s : stones) maxHeap.push(s);

        while(maxHeap.size() >= 2){
            int top1 = maxHeap.top(); maxHeap.pop();
            int top2 = maxHeap.top(); maxHeap.pop();
            if(top1 > top2) {
                maxHeap.push(top1-top2);
            }
        }
        return maxHeap.top();
    }
};
