class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, bool> hashMap;
        for (int n : nums){
            hashMap[n] = true;
        }
        int result = 0;
        for (int n : nums){
            if (hashMap.find(n - 1) != hashMap.end()){
                continue;
            }
            int i = 0;
            while (hashMap.find(n + i) != hashMap.end()){
                i++;
            }
            result = max(result, i);
        }
        return result;
    }
};