class Solution {
public:
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        unordered_map<string, bool> exactCheck;
        unordered_map<string, string> capitalCheck;
        unordered_map<string, string> vowelCheck;

        for (string word : wordlist){
            exactCheck[word] = true;
        }

        for (string word : wordlist){
            string s = word;
            transform(s.begin(), s.end(), s.begin(), ::tolower);
            if (capitalCheck.find(s) == capitalCheck.end()){
                capitalCheck[s] = word;
            }
        }

        for (string word: wordlist){
            string tempWord = word;
            transform(tempWord.begin(), tempWord.end(), tempWord.begin(), ::tolower);

            for (int i = 0; i < tempWord.size(); i++){
                if (isVowel(tempWord[i])){
                    tempWord[i] = '*';
                }
            }

            if (vowelCheck.find(tempWord) == vowelCheck.end()){
                vowelCheck[tempWord] = word;
            }
        }

        for (int i = 0; i < queries.size(); i++){
            if (exactCheck[queries[i]]){
                continue;
            }

            string tempWord = queries[i];
            transform(tempWord.begin(), tempWord.end(), tempWord.begin(), ::tolower);
            if (capitalCheck.find(tempWord) != capitalCheck.end()){
                queries[i] = capitalCheck[tempWord];
                continue;
            }

            for (int i = 0; i < tempWord.size(); i++){
                if (isVowel(tempWord[i])){
                    tempWord[i] = '*';
                }
            }

            if (vowelCheck.find(tempWord) != vowelCheck.end()){
                queries[i] = vowelCheck[tempWord];
                continue;
            }

            queries[i] = "";
        }

        return queries;
        
    }

    bool isVowel(char ch){
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    }
};