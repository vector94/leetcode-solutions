class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> count;
        for (int num : arr){
            count[num]++;
        }
        unordered_map<int, int> track;
        for(auto it : count){
            if (track.find(it.second) != track.end()){
                return false;
            }   
            track[it.second]++;
        }
        return true;
    }
};