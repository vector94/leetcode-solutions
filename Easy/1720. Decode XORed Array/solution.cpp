class Solution {
public:
    vector<int> decode(vector<int>& encoded, int first) {
        vector<int> ret;
        ret.push_back(first);
        for (auto x : encoded){
            ret.push_back(ret.back() ^ x);
        }
        return ret;
    }
};