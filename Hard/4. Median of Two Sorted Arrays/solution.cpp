class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> v;
        int i, j;
        i = j = 0;
        while (i < nums1.size() && j < nums2.size()){
            if (nums1[i] <= nums2[j]){
                v.push_back(nums1[i]);
                i++;
            }
            else{
                v.push_back(nums2[j]);
                j++;
            }
        }
        while (i < nums1.size()){
            v.push_back(nums1[i]);
            i++;
        }
        while (j < nums2.size()){
            v.push_back(nums2[j]);
            j++;
        }
        int sz = v.size();
        double ret;
        if (sz & 1){
            ret = v[sz / 2];
        }
        else{
            ret = (v[sz / 2] + v[sz / 2 - 1]) / 2.0;
        }
        return ret;
    }
};