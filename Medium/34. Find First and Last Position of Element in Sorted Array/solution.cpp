class Solution {
public:
    
    int Search(vector<int> &nums, int target, bool searchLeft){
        
        int low = 0;
        int high = nums.size() - 1;
        int ret = -1;
        
        while (low <= high){
            int mid = low + (high - low) / 2;
            if (nums[mid] == target){
                ret = mid;
                if (searchLeft){
                    high = mid - 1;
                }
                else{
                    low = mid + 1;
                }
            }
            else if (nums[mid] < target){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
        
        return ret;
    }
    
    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.size() == 0)   return vector<int> ({-1, -1});
        vector<int> result(2);
        result[0] = Search(nums, target, 1);
        result[1] = Search(nums, target, 0);
        return result;
    }
};