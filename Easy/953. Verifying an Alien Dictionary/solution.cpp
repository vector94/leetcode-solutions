class Solution {
public:
    bool isSmallOrEqual(string word1, string word2, unordered_map<char, int> &wordOrder){
        int i, j;
        i = j = 0;
        while (i < word1.size()){
            if (j == word2.size() || wordOrder[word1[i]] > wordOrder[word2[j]]){
                return false;
            }
            if (wordOrder[word1[i]] < wordOrder[word2[j]]){
                return true;
            }
            i++;
            j++;
        }
        return true;
    }

    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char, int> wordOrder;
        for (int i = 0; i < order.size(); i++){
            wordOrder[order[i]] = i;
        }

        for (int i = 0; i < words.size(); i++){
            for (int j = i + 1; j < words.size(); j++){
                if (!isSmallOrEqual(words[i], words[j], wordOrder)){
                    return false;
                }
            }
        }
        return true;
    }
};