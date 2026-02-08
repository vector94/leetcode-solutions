class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string> > myMap;
        for (string s : strs){
            string temp = s;
            sort(temp.begin(), temp.end());
            myMap[temp].push_back(s);
        }
        vector<vector<string> > result;
        for (auto it : myMap){
            result.push_back(it.second);
        }
        return result;
    }
};