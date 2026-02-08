class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int left, right;
        left = right = -1;
        
        int low = 0, high = nums.size() - 1;
        while (low <= high){
            int mid = low + (high - low) / 2;
            if (nums[mid] == target)    left = mid;
            if (nums[mid] >= target){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        
        low = 0, high = nums.size() - 1;
        while (low <= high){
            int mid = low + (high - low) / 2;
            if (nums[mid] == target)    right = mid;
            if (nums[mid] <= target){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
        
        return vector<int>{left, right};
    }
};