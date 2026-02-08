class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int first, second;
        first = second = INT_MAX;
        for (int num : nums){
            if (num <= first){
                first = num;
            }
            else if (num <= second){
                second = num;
            }
            else{
                return true;
            }
        }
        return false;
    }
};