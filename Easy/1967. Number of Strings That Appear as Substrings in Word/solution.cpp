class Solution {
public:

    bool check(string word, string pattern){
        int pLen = pattern.size();
        if (pLen > word.size()) return false;

        for (int i = 0; i <= word.size() - pLen; i++){
            if (word.substr(i, pLen) == pattern){
                return true;
            }
        }

        return false;
    }

    int numOfStrings(vector<string>& patterns, string word) {
        int ans = 0;

        for (int i = 0; i < patterns.size(); i++){
            if (check(word, patterns[i])){
                ans++;
            }
        }

        return ans;
    }
};