
class StreamChecker {
    
    string bigWord;
    
    struct Node{
        bool endmark;
        Node *next[26];
        Node(){
            endmark = false;
            for (int i = 0; i < 26; i++){
                next[i] = NULL;
            }
        }
    } *root;
    
    void Insert(string s){
        Node *cur = root;
        for (int i = 0; i < s.size(); i++){
            int id = s[i] - 'a';
            if (cur -> next[id] == NULL){
                cur -> next[id] = new Node();
            }
            cur = cur -> next[id];
        }
        cur -> endmark = true;
    }
    
    bool Search(){
        int i = bigWord.size() - 1;
        Node *cur = root;
        while (i >= 0){
            if (cur -> endmark){
                break;
            }
            int id = bigWord[i] - 'a';
            if (cur -> next[id] == NULL){
                return false;
            }
            cur = cur -> next[id];
            i--;
        }
        return cur -> endmark;
    }
    
public:
    
    StreamChecker(vector<string>& words) {
        root = new Node();
        for (int i = 0; i < words.size(); i++){
            string s = words[i];
            reverse(s.begin(), s.end());
            Insert(s);
        }
        
    }
    
    bool query(char letter) {
        bigWord.push_back(letter);
        if (Search())   return true;
        return false;
    }
};

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */