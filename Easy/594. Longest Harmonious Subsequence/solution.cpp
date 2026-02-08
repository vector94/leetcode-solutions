class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_set<int> mySet;
        unordered_map<int, int> freq;

        for (int n : nums){
            mySet.insert(n);
            freq[n]++;
        }

        int ans = 0;
        for (auto n : mySet){
            if (freq[n + 1] > 0){
                ans = max(ans, freq[n] + freq[n + 1]);
            }
        }

        return ans;
    }
};