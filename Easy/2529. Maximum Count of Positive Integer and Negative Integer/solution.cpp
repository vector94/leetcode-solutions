class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int pos, neg;
        pos = neg = 0;

        for (int x : nums){
            if (x < 0)  neg++;
            else if (x > 0) pos++;
        }

        return max(pos, neg);
    }
};