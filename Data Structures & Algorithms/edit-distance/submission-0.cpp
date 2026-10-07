class Solution {
public:
    int minDistance(string word1, string word2) {
        return dfs(0,0,word1,word2);
    }

    int dfs(int i, int j, string word1, string word2){
        if(j >= word2.size()){
            return word1.size() - i;
        }
        if(i>= word1.size()){
            return word2.size() - j;
        }

        // skip if both words char matches
        int skip = INT_MAX;
        if(word1[i] == word2[j]) {
            skip = dfs(i+1,j+1,word1,word2);
        }

        // insert
        int insert = dfs(i,j+1,word1,word2);

        // delete
        int del = dfs(i+1,j,word1,word2);
        //replace
        int replace = dfs(i+1, j+1,word1,word2);

        return min(skip, 1+min(insert, min(del,replace)));
    }
};
