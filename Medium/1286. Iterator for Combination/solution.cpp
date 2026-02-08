void backtrack(int index, string characters, int length, string &s, vector<string> &v){
    if (length == 0){
        v.push_back(s);
        return;
    }
    if (index == characters.size()){
        return;
    }
    
    for (int i = index; i < characters.size(); i++){
        s.push_back(characters[i]);
        backtrack(i + 1, characters, length - 1, s, v);
        s.pop_back();
    }
}

class CombinationIterator {
public:
    
    vector<string> v;
    string s;
    int curIndex = 0;
    
    CombinationIterator(string characters, int combinationLength) {
        backtrack(0, characters, combinationLength, s, v);
        sort(v.begin(), v.end());
    }
    
    string next() {
        return v[curIndex++];
    }
    
    bool hasNext() {
        if (curIndex< v.size())    return true;
        return false;
    }
};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */