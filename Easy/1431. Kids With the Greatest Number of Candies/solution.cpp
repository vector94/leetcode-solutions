class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int mx = 0;
        for (auto x : candies){
            mx = max(mx, x);
        }
        vector<bool> ret;
        for (auto x : candies){
            if (extraCandies + x >= mx){
                ret.push_back(true);
            }
            else{
                ret.push_back(false);
            }
        }
        return ret;
    }
};