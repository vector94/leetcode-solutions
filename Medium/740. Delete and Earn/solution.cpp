class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        
        vector<int> count(10005, 0);
        
        for (int i = 0; i < nums.size(); i++){
            count[nums[i]]++;
        }
        
        int first = 0;
        int second = count[1];
        
        for (int i = 2; i <= 10000; i++){
            int current = max(first + count[i] * i, second);
            first = second;
            second = current;
        }
        
        return second;
    }
};