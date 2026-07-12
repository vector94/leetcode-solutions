class Solution {
    vector<int> freq;
public:
    string frequencySort(string s) {
        unordered_map<char, int> freq;
        vector<string> bucket(s.size() + 1, "");
        for (char ch : s){
            freq[ch]++;
        }
        for (auto it : freq){
            bucket[it.second].append(it.second, it.first);
        }
        string result = "";
        for (int i = s.size(); i >= 1; i--){
            if (!bucket[i].empty()){
                result += bucket[i];
            }
        }
        return result;
    }
};