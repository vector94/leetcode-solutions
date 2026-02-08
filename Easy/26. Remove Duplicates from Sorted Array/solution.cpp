class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        set<int> st;
        vector<int> ret;
        for (auto x : nums){
            if (!st.empty() && st.find(x) != st.end()){
                continue;
            }
            st.insert(x);
            ret.push_back(x);
        }
        nums = ret;
        return nums.size();
    }
};