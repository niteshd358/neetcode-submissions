class WordDictionary {
    vector<string> store;
public:
    WordDictionary() {
        
    }
    
    void addWord(string word) {
        store.push_back(word);
    }
    
    bool search(string word) {
        for(string &w : store){
            if(w.length() != word.length()) continue;
            int i = 0;
            for(; i <word.length() ; ++i){
                if(w[i] == word[i] || word[i] == '.') {
                    continue;
                }
                else{
                    break;
                }
            }
            if(i == word.length()) return true;
        }
        return false;
    }
};
