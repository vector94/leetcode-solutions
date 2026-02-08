class Solution {
public:
    bool divideArray(vector<int>& nums) {
        vector<int> cnt(501, 0);
        for (int n : nums){
            cnt[n]++;
        }

        for (int i = 1; i <= 500; i++){
            if (cnt[i] % 2 == 1) return false;
        }

        return true;
    }
};