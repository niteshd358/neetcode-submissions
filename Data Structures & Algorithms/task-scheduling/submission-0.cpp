class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26,0);
        for(char task : tasks) freq[task - 'A']++;

        // maxheap
        priority_queue<int> maxHeap;
        for(int i=0; i<freq.size(); i++){
            if(freq[i]){
                maxHeap.push(freq[i]);
            }
        }

        int time = 0;
        queue<pair<int,int>> q;
        while(!maxHeap.empty() || !q.empty()){
            time++;

            if(maxHeap.empty()){
                time = q.front().second;
            }else{
                int cnt = maxHeap.top() - 1;
                maxHeap.pop();
                if(cnt > 0){
                    q.push({cnt, time+n});
                }
            }

            if(!q.empty() && q.front().second == time){
                maxHeap.push(q.front().first);
                q.pop();
            }
        }
        return time;
    }
};
