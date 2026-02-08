class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        int i, j;
        i = j = 0;
        set<int> st;
        while (i < nums1.size() && j < nums2.size()){
            if (nums1[i] == nums2[j]){
                st.insert(nums1[i]);
                i++;
                j++;
            }
            else if (nums1[i] < nums2[j]){
                i++;
            }
            else{
                j++;
            }
        }
        vector<int> ret;
        for (auto x : st){
            ret.push_back(x);
        }
        return ret;
    }
};