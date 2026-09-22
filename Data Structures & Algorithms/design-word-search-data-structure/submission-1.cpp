class TrieNode {
public:
    vector<TrieNode*> children;
    bool word;

    TrieNode(){
        children = vector<TrieNode*>(26,nullptr); 
        word = false;
    }
};

class WordDictionary {
    TrieNode* root;
public:
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode* curr = root;
        for(char &c : word){
            int i = c - 'a';
            if(curr->children[i] == nullptr){
                curr->children[i] = new TrieNode();
            }
            curr = curr->children[i];
        }
        curr->word = true;
    }
    
    bool search(string word) {
        return dfs(word, 0 , root);
    }

private:
    bool dfs(string word, int j, TrieNode* root){
        TrieNode* curr = root;
        for(int i=j; i<word.length(); ++i){
            char c = word[i];
            if(c == '.'){
                for(TrieNode* child : curr->children){
                    if(child != nullptr && dfs(word, i+1, child)){
                        return true;
                    }
                }
                return false;
            }
            else{
                if(curr->children[c-'a'] == nullptr){
                    return false;
                }
                curr = curr->children[c-'a'];
            }
        }
        return curr->word ? true : false;
    }
};
