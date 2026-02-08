class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        set<int> mySet;

        for (int n : nums){
            mySet.insert(n);
        }

        while (mySet.find(original) != mySet.end()){
            original *= 2;
        }

        return original;
    }
};