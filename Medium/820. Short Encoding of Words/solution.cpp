class Solution {
public:

    struct node {
        node *next[26];
        node(){
            for (int i = 0; i < 26; i++){
                next[i] = NULL;
            }
        }
    } *root;
    
    void Insert(string s){
        node *cur = root;
        for (int i = 0; i < s.size(); i++){
            int id = s[i] - 'a';
            // cout << s << " " << id << endl;
            if (cur -> next[id] == NULL){
                cur -> next[id] = new node();
            }
            cur = cur -> next[id];
        }
    }
    
    bool check(node *cur){
        bool flag = true;
        for (int i = 0; i < 26; i++){
            if (cur -> next[i]) flag = false;
        }
        return flag;
    }
    
    int Query(node *cur, int count){
        if (check(cur)){
            return count;
        }
        int ret = 0;
        for (int id = 0; id < 26; id++){
            if (cur -> next[id]){
                // cout << id << " " << count << endl;
                ret += Query(cur -> next[id], count + 1);
            }
        }
        return ret;
    }
    
    int minimumLengthEncoding(vector<string>& words) {
        root = new node();
        for (string w : words){
            reverse(w.begin(), w.end());
            Insert(w);
        }
        return Query(root, 1);
    }
};