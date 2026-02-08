class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int sum = 0;
        int minSum = 0;
        int result;
        for (auto n : nums){
            sum += n;
            minSum = min(minSum, sum);
            result = 1 - minSum;
        }
        return result;
    }
};