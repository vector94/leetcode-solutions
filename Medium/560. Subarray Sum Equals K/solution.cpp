class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> count;
        int sum = 0;
        int result = 0;
        for (int n : nums){
            count[sum]++;
            sum += n;
            result += count[sum - k];   
        } 
        return result;
    }
};