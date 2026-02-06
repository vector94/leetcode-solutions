class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int target = 0;
        for (int n : nums){
            target += n;
            target %= p;
        }

        if (target == 0)  return 0;

        map<int, int> myMap;
        myMap[0] = -1;

        int curSum = 0;
        int ans = nums.size();
        for (int i = 0; i < nums.size(); i++){
            curSum += nums[i];
            curSum %= p;

            int needed = (curSum - target + p) % p;

            if (myMap.find(needed) != myMap.end()){
                ans = min(ans, i - myMap[needed]);
            }
            myMap[curSum] = i;
        }

        if (ans == nums.size()) return -1;
        return ans;
    }
};