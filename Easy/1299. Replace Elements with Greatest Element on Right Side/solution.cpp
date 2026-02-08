class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        vector<int> ret;
        ret.push_back(-1);
        int mx = arr.back();
        for (int i = arr.size() - 2; i >= 0; i--){
            ret.push_back(mx);
            mx = max(arr[i], mx);
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }
};