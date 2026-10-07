class Solution {
public:
    int minDistance(string word1, string word2) {
        return dfs(0,0,word1,word2);
    }

    int dfs(int i, int j, string word1, string word2){
        // word2 exhausted
        if(j >= word2.size()){
            return word1.size() - i;
        }
        // word1 exhausted
        if(i>= word1.size()){
            return word2.size() - j;
        }

        // skip if Characters already match
        if(word1[i] == word2[j]) {
            return dfs(i+1,j+1,word1,word2);
        }

        // insert
        int insert = dfs(i,j+1,word1,word2);

        // delete
        int del = dfs(i+1,j,word1,word2);
        //replace
        int replace = dfs(i+1, j+1,word1,word2);

        return 1 + min({insert,del,replace});
    }
};
