class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        unordered_map<int, int> hashMap;
        for (int n : nums){
            hashMap[n]++;
        }
        
        int result = 0;
        for (auto it : hashMap){
            if (k == 0 && hashMap[it.first] > 1){
                result++;
            }
            else if (k > 0 && hashMap.find(it.first - k) != hashMap.end()){
                result++;
            }
        }
        
        return result;
    }
};