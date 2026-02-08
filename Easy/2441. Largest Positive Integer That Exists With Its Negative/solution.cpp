class Solution {
public:
    int findMaxK(vector<int>& nums) {
        unordered_map<int, bool> myMap;
        
        int ans = -1;
        
        for (int n : nums){
            if (myMap.find(-n) != myMap.end()){
                ans = max(ans, abs(n));
            }
            myMap[n] = true;
        }
        
        return ans;
    }
};