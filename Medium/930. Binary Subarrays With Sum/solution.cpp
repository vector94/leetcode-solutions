class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return myHelper(nums, goal) - myHelper(nums, goal - 1);
    }
    
    int myHelper(vector<int>& nums, int goal){
        if (goal < 0)   return 0;
        
        int total = 0;
        int left, cur;
        left = cur = 0;
        
        for (int right =  0; right < nums.size(); right++){
            cur += nums[right];
            
            while (cur > goal){
                cur -= nums[left];
                left++;
            }
            
            total += (right - left + 1);
        }
        
        return total;
    }
};