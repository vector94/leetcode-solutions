class Solution {
public:
    bool wordPattern(string pattern, string data) {
        stringstream s(data);
        string str;
        
        int n = pattern.size();
        vector<string> charToWord(26);
        unordered_map<string, char> wordToChar;
        
        int i = 0;
        while (getline(s, str, ' ')){
            if (i == pattern.size())    return false;
            
            int index = pattern[i] - 'a';
            if (charToWord[index].size() == 0 && wordToChar.find(str) == wordToChar.end()){
                charToWord[index] = str;
                wordToChar[str] = pattern[i];
            }
            else{
                if (charToWord[index] != str || wordToChar[str] != pattern[i]) return false;
            }
            i++;
        }
        
        return (i == pattern.size());
    }
};