class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string>st(wordList.begin(),wordList.end());

        if(st.find(endWord) == st.end()) return 0;

        queue<string>q;
        q.push(beginWord);
        int cnt = 1;

        while(!q.empty()){
            int size = q.size();
            while(size--){
                string currWord = q.front();
                q.pop();
                if(currWord == endWord) return cnt;
                for(int i=0; i<currWord.size(); ++i){
                    char c = currWord[i];
                    for(char j='a'; j<='z'; ++j){
                        currWord[i] = j;
                        if(st.find(currWord) != st.end()){
                            q.push(currWord);
                            st.erase(currWord);
                        }
                    }
                    currWord[i] = c;
                }
            }
            cnt++;
        }

        return cnt;
    }
};
