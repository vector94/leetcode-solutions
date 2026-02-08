class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int Xor = 0;
        for (int n : nums){
            Xor ^= n;
        }
        return Xor;
    }
};