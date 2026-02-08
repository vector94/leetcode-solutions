class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int, int> freq;

        for (int n : arr){
            freq[n]++;
        }

        int ans = -1;
        for (int n : arr){
            if (freq[n] == n){
                ans = max(ans, n);
            }
        }

        return ans;
    }
};