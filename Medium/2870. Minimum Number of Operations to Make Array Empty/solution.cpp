class Solution {
public:
    int minOperations(vector<int>& nums) {
        int ans = 0;
        map<int, int> count;

        for (int n : nums){
            count[n]++;
        }

        for (auto it : count){
            if (it.second == 1){
                return -1;
            }

            if (it.second % 3 == 0){
                ans += it.second / 3;
            }
            else if (it.second % 3 == 1){
                ans += ((it.second - 4) / 3) + 2;
            }
            else{
                ans += (it.second / 3) + 1;
            }
        }

        return ans;
    }
};