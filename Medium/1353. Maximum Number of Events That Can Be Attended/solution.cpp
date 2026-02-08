class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        int N = events.size();

        sort(events.begin(), events.end());

        priority_queue<int, vector<int>, greater<int>> PQ;

        int day = events[0][0];
        int i = 0;
        int cnt = 0;

        while (!PQ.empty() || i < N){
            if (PQ.empty()){
                day = events[i][0];
            }

            while (i < N && events[i][0] == day){
                PQ.push(events[i][1]);
                i++;
            }

            if (!PQ.empty()){
                PQ.pop();
                cnt++;
            }

            day++;

            while (!PQ.empty() && PQ.top() < day){
                PQ.pop();
            }
        }

        return cnt;
    }
};