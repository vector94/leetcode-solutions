class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        set<vector<int> > st;
        int n = nums.size();
        for (int i = 0; i <= (1 << n); i++){
            vector<int> v;
            for (int j = 0; j < n; j++){
                if (i & (1 << j)){
                    v.push_back(nums[j]);
                }
            }
            sort(v.begin(), v.end());
            st.insert(v);
        }
        vector<vector<int>> ret;
        for (auto x : st){
            ret.push_back(x);
        }
        return ret;
    }
};