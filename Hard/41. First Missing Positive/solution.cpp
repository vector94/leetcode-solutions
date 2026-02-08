class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        unordered_map<int, bool> myMap;
        
        int n = nums.size();
        
        for (int i = 0; i < n; i++){
            myMap[nums[i]] = true;
        }
        
        for (int i = 1; i <= n; i++){
            if (myMap.find(i) == myMap.end()){
                return i;
            }
        }
        return n + 1;
    }
};