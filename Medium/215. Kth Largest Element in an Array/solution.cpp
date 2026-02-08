class Solution {
public:
    
    int quickSelect(int left, int right, vector<int> &nums, int k){
        
        int pivot = right;
        
        int pre, cur;
        pre = cur = left;
        while (cur < right){
            if (nums[cur] < nums[pivot]){
                swap(nums[cur], nums[pre]);
                pre++;
            }
            cur++;
        }
        
        swap(nums[pre], nums[pivot]);
        pivot = pre;
        
        if (nums.size() - k == pivot)   return nums[pivot];
        if (nums.size() - k < pivot){
            return quickSelect(left, pivot - 1, nums, k);
        }
        else{
            return quickSelect(pivot + 1, right, nums, k);
        }
    }
    
    int findKthLargest(vector<int>& nums, int k) {
        return quickSelect(0, nums.size() - 1, nums, k);
    }
};