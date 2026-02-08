class Solution {
public:
    int minSwaps(vector<int>& data) {
        int totalOneCnt = 0;
        for (int d : data){
            totalOneCnt += d;
        }
        if (totalOneCnt == 0)   return 0;
        int result = data.size();
        int curZeroCnt = 0;
        int left = 0, right = 0;
        while (right < data.size()){
            curZeroCnt += data[right] == 0 ? 1 : 0;
            if (right - left == totalOneCnt - 1){
                result = min(result, curZeroCnt);
                curZeroCnt -= data[left] == 0 ? 1 : 0;
                left++;
            }
            right++;
        }
        return result;
    }
};