class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        unordered_map<int, bool> hashMap;
        int N = nums.size();

        int ans = 0;
        for (int i = N - 1; i >= 0; i--){
            if (hashMap[nums[i]]){
                ans = (i + 3) / 3;
                break;
            }
            
            hashMap[nums[i]] = true;
        }

        return ans;
    }
};