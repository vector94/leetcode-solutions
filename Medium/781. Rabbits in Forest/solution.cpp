class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int, int> myMap;
        for (int n : answers){
            myMap[n]++;
        }

        int result = 0;
        for (auto it : myMap){
            result += ((it.second + it.first) / (it.first + 1)) * (it.first + 1);
        }

        return result;
    }
};