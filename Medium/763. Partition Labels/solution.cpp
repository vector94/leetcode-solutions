class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> lastIndex(26);
        for (int i = 0; i < s.size(); i++){
            lastIndex[s[i] - 'a'] = i;
        }
        
        vector<int> result;
        int preIndex = -1;
        int nextIndex = 0;
        for (int i = 0; i < s.size(); i++){
            nextIndex = max(nextIndex, lastIndex[s[i] - 'a']);
            if (nextIndex == i){
                result.push_back(i - preIndex);
                preIndex = i;
                nextIndex = i + 1;
            }
        }
        
        return result;
    }
};