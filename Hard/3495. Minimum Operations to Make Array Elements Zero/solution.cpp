class Solution {
public:
    long long minOperations(vector<vector<int>>& queries) {
        long long ans = 0;

        for (int i = 0; i < queries.size(); i++){
            long long l = queries[i][0];
            long long r = queries[i][1];
            long long totalSteps = 0;

            long long curPow = 4;
            long long curSteps = 1;

            long long curLeft = 1;
            long long curRight = 3;

            while (curRight <= r){
                if (l <= curRight){
                    int cnt = curRight - l + 1;
                    totalSteps += cnt * curSteps;
                    l = curRight + 1;
                }

                curSteps++;
                curLeft = curPow;
                curPow *= 4;
                curRight = curPow - 1;
            }


            l = max(l, curLeft);
            long long cnt = r - l + 1;
            totalSteps += cnt * curSteps;

            ans += (totalSteps + 1) / 2;
        }

        return ans;
    }
};

/*
    0 to 3 -> 1
    4 to 15 -> 2
    16 to 63 -> 3
    64 to 255 -> 4
*/