class Solution {
public:
    int calculateTime(string keyboard, string word) {
        unordered_map<int, int> hashMap;
        for (int i = 0; i < keyboard.size(); i++){
            hashMap[keyboard[i]] = i;
        }

        int result = hashMap[word[0]];
        for (int i = 1; i < word.size(); i++){
            result += abs(hashMap[word[i - 1]] - hashMap[word[i]]);
        }
        return result;
    }
};