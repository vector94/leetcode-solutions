class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        
        unordered_map<int, int> myMap;
        
        int sum = 0;
        int result = 0;
        
        for (int i = 0; i < nums.size(); i++){
            myMap[sum]++;
            
            sum += nums[i];
            
            int need = sum - k;
            
            result += myMap[need];
        }
        
        return result;
    }
};