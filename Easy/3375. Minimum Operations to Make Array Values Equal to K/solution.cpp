class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        unordered_set<int> mySet;

        for (int n : nums){
            if (n < k)  return -1;
            if (n > k)  mySet.insert(n);
        }

        return mySet.size();
    }
};