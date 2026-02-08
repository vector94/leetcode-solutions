class Trie {
public:
    
    struct Node{
        bool endmark;
        Node* next[26];
        Node(){
            endmark = false;
            for (int i = 0; i < 26; i++){
                next[i] = NULL;
            }
        }
    } *root;
    
    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        Node* cur = root;
        
        for (int i = 0; i < word.size(); i++){
            int ch = word[i] - 'a';
            if (cur -> next[ch] == NULL){
                cur -> next[ch] = new Node();
            }
            cur = cur -> next[ch];
        }
        
        cur -> endmark = true;
    }
    
    bool search(string word) {
        Node* cur = root;
        
        for (int i = 0; i < word.size(); i++){
            int ch = word[i] - 'a';
            if (cur -> next[ch] == NULL)    return false;
            cur = cur -> next[ch];
        }
        
        return cur -> endmark;
    }
    
    bool startsWith(string prefix) {
        Node* cur = root;
        
        for (int i = 0; i < prefix.size(); i++){
            int ch = prefix[i] - 'a';
            if (cur -> next[ch] == NULL)    return false;
            cur = cur -> next[ch];
        }
        
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */