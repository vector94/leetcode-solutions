class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<string, int> hashMap;
        for (int i = 0; i <= (int)s.size() - 10; i++){
            string curSubStr = s.substr(i, 10);
            hashMap[curSubStr]++;
        }
        vector<string> result;
        for (auto it : hashMap){
            if (it.second > 1)  result.push_back(it.first);
        }
        return result;
    }
};