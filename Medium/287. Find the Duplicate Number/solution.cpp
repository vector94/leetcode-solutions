class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int fast = nums[0];
        int slow = nums[0];
        
        do{
            slow = nums[slow];
            fast = nums[nums[fast]];
        }while (fast != slow);
        
        int first = nums[0];
        while (first != slow){
            first = nums[first];
            slow = nums[slow];
        }
        return first;
    }
};