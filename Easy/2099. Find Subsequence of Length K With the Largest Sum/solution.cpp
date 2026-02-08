class Solution {
public:

    bool static cmp(pair<int, int> a, pair<int, int> b){
        return a.second < b.second;
    }

    vector<int> maxSubsequence(vector<int>& nums, int k) {
        vector<pair<int, int>> numsWithIdx;

        for (int i = 0; i < nums.size(); i++){
            numsWithIdx.push_back({nums[i], i});
        }

        sort(numsWithIdx.begin(), numsWithIdx.end());

        vector<pair<int, int>> resultSeqWithIdx;
        for (int i = numsWithIdx.size() - 1, j = 0; j < k; i--, j++){
            resultSeqWithIdx.push_back(numsWithIdx[i]);
        }

        sort(resultSeqWithIdx.begin(), resultSeqWithIdx.end(), cmp);
        vector<int> result;

        for (int i = 0; i < k; i++){
            result.push_back(resultSeqWithIdx[i].first);
        }

        return result;
    }
};