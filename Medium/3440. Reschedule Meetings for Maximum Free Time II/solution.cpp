class Solution {
public:
    int maxFreeTime(int eventTime, vector<int>& startTime, vector<int>& endTime) {
        vector<int> gaps;
        gaps.push_back(startTime[0]);

        for (int i = 1; i < startTime.size(); i++){
            gaps.push_back(startTime[i] - endTime[i - 1]);
        }

        gaps.push_back(eventTime - endTime.back());

        int ans = 0;
        for (int i = 1; i < gaps.size(); i++){
            ans = max(ans, gaps[i] + gaps[i - 1]);
        }

        int preBigGap = gaps[0];
        for (int i = 1; i < startTime.size(); i++){
            int curMeetingLength = endTime[i] - startTime[i];
            if (preBigGap >= curMeetingLength){
                ans = max(ans, gaps[i] + curMeetingLength + gaps[i + 1]);
            } 

            preBigGap = max(preBigGap, gaps[i]);
        }

        int nextBigGap = gaps.back();
        for (int i = startTime.size() - 2; i >= 0; i--){
            int curMeetingLength = endTime[i] - startTime[i];

            if (nextBigGap >= curMeetingLength){
                ans = max(ans, gaps[i] + curMeetingLength + gaps[i + 1]);
            } 

            // cout << i << " " << curMeetingLength << " " << gaps[i] << " " << gaps[i + 1] << " " << nextBigGap << endl;

            nextBigGap = max(nextBigGap, gaps[i + 1]);
        }

        return ans;
    }

};