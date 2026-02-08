class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<int> maxCount(26, 0);
        for (string word : words2){
            vector<int> curCount(26, 0);
            for (char ch : word){
                curCount[ch - 'a']++;
                maxCount[ch - 'a'] = max(maxCount[ch - 'a'], curCount[ch - 'a']);
            }
        }
        vector<string> result;
        for (string word : words1){
            vector<int> curCount(26, 0);
            for (char ch : word){
                curCount[ch - 'a']++;
            }
            bool flag = true;
            for (int i = 0; i < 26; i++){
                if (curCount[i] < maxCount[i]){
                    flag = false;
                    break;
                }
            }
            if (flag){
                result.push_back(word);
            }
        }
        return result;
    }
};