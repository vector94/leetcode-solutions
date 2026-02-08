class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        vector<int> gaps;
        gaps.push_back(startTime[0]);

        for (int i = 1; i < startTime.size(); i++){
            gaps.push_back(startTime[i] - endTime[i - 1]);
        }

        gaps.push_back(eventTime - endTime.back());

        int ans = 0;
        int left = 0;
        int right = 0;
        int curGap = 0;

        while (right < gaps.size()){
            curGap += gaps[right];
            ans = max(ans, curGap);

            if (right - left == k){
                curGap -= gaps[left];    
                left++;
            }

            right++;
        }

        return ans;
    }
};