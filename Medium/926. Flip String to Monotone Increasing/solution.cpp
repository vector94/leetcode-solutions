class Solution {
public:
    int minFlipsMonoIncr(string s) {
        vector<int> prefixSum;
        prefixSum.push_back(0);
        for (int i = 0; i < s.size(); i++){
            prefixSum.push_back((s[i] - '0') + prefixSum.back());
        }
        int result = min((int)prefixSum.back(), (int)s.size() - prefixSum.back());
        for (int i = 0; i < s.size(); i++){
            int oneOnRight = prefixSum.back() - prefixSum[i + 1];
            int spotOnRight = s.size() - (i + 1);
            int oneOnLeft = prefixSum[i + 1];
            result = min(result, spotOnRight - oneOnRight + oneOnLeft);            
        }
        return result;
    }
};