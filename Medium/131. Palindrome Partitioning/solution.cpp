class Solution {
public:
    
    bool checkPalindrome(string s){
        for (int i = 0, j = s.size() - 1; i < s.size() / 2; i++, j--){
            if (s[i] != s[j])   return false;
        }
        return true;
    }
    
    void backtrack(int idx, string &s, vector<string> &p, vector<vector<string> > &result){
        if (idx == s.size()){
            result.push_back(p);
            return;
        }
        for (int i = idx; i < s.size(); i++){
            if (checkPalindrome(s.substr(idx, i - idx + 1))){
                p.push_back(s.substr(idx, i - idx + 1));
                backtrack(i + 1, s, p, result);
                p.pop_back();
            }
        }
    }
    
    vector<vector<string>> partition(string s) {
        vector<vector<string> > result;
        vector<string> p;
        backtrack(0, s, p, result);
        return result;
    }
};