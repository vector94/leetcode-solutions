class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<string, char> wordToChar;
        vector<string> charToWord(26);
        stringstream ss(s);
        string word;
        int i = 0;
        while (ss >> word){
            if (i == pattern.size())    return false;
            if (charToWord[pattern[i] - 'a'].size() == 0 && wordToChar.find(word) == wordToChar.end()){
                charToWord[pattern[i] - 'a'] = word;
                wordToChar[word] = pattern[i];
            }
            else if (charToWord[pattern[i] - 'a'] != word || wordToChar[word] != pattern[i]){
                return false;
            }
            i++;
        }
        return (i == pattern.size());
    }
};