class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
        vector<int> result;

        for (int i = 0; i < words.size(); i++){
            string w = words[i];
            for (char ch : w){
                if (ch == x){
                    result.push_back(i);
                    break;
                }
            }
        }

        return result;
    }
};