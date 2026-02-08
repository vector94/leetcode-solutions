class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<pair<int, int>> pairNums;

        for (int i = 0; i < nums.size(); i++){
            pairNums.push_back({nums[i], i});
        }
        sort(pairNums.begin(), pairNums.end());

        int prevCnt = 0;
        int N = nums.size();
        vector<int> result(N);

        for (int i = 0; i < pairNums.size(); i++){
            int curNum = pairNums[i].first;
            int curCnt = 0;
            while (i < pairNums.size() && pairNums[i].first == curNum){
                curCnt++;
                result[pairNums[i].second] = prevCnt;
                i++;
            }
            i--;
            prevCnt += curCnt;
        }

        return result;
    }
};