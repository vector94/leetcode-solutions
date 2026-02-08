class WordDictionary {
public:
    
    struct node {
        node *next[26];
        bool endmark;
        node(){
            endmark = false;
            for (int i = 0; i < 26; i++){
                next[i] = NULL;
            }
        }
    } *root;
    
    WordDictionary() {
        root = new node();
    }
    
    void addWord(string word) {
        node *cur = root;
        for (int i = 0; i < word.size(); i++){
            int id = word[i] - 'a';
            if (cur -> next[id] == NULL){
                cur -> next[id] = new node();
            }
            cur = cur -> next[id];
        }
        cur -> endmark = true;
    }
    
    bool searchHelper(int index, node* cur, string &word){
        if (index == word.size()){
            return cur -> endmark;
        }
        
        if (word[index] == '.'){
            bool ret = false;
            for (int id = 0; id < 26; id++){
                if (cur -> next[id] != NULL){
                    ret |= searchHelper(index + 1, cur -> next[id], word);
                }
            }
            return ret;
        }
        else{
            int id = word[index] - 'a';
            if (cur -> next[id] == NULL)    return false;
            return searchHelper(index + 1, cur -> next[id], word);
        }
    }
    
    bool search(string word) {
        node *cur = root;
        return searchHelper(0, cur, word);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */