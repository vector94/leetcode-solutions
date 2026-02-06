class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        int N = nums.size() / 2;

        unordered_map<int, int> myMap;
        for (int n : nums){
            myMap[n]++;

            if (myMap[n] == N){
                return n;
            }
        }

        return 0;
    }
};