class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int minNum, maxNum;
        
        minNum = INT_MAX;
        bool flag = false;
        for (int i = 1; i < nums.size(); i++){
            if (nums[i] < nums[i - 1])  flag = true;
            if (flag) minNum = min(minNum, nums[i]);
        }
        
        maxNum = INT_MIN;
        flag = false;
        for (int i = nums.size() - 2; i >= 0; i--){
            if (nums[i] > nums[i + 1])  flag = true;
            if (flag)   maxNum = max(maxNum, nums[i]);
        }
        
        int l = 0;
        while (l < nums.size()){
            if (minNum < nums[l])   break;
            l++;
        }
        int r = nums.size() - 1;
        while (r >= 0){
            if (maxNum > nums[r])   break;
            r--;
        }
        if (r > l)
            return r - l + 1;
        return 0;
    }
};