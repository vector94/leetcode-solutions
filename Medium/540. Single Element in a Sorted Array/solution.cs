public class Solution {
    public int SingleNonDuplicate(int[] nums) {
        
        int low = 0;
        int high = nums.Length - 1;
        
        int result = 0;
        while (low < high){
            
            int mid = low + (high - low) / 2;
            if (mid % 2 == 0 && nums[mid] == nums[mid + 1] || mid % 2 == 1 && nums[mid] == nums[mid - 1]){
                low = mid + 1;
            }
            
            else{
                high = mid;
            }
            
        }
        
        return nums[low];
    }
}