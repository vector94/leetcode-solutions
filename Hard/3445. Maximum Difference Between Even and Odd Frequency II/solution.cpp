class Solution {
public:
    int maxDifference(string s, int k) {
        int result = INT_MIN;
        for (char i = '0'; i <= '4'; i++){
            for (char j = '0'; j <= '4'; j++){
                if (i == j) continue;

                result = max(result, solve(i, j, s, k));
            }
        }

        return result;
    }

    int solve(char a, char b, string s, int k){
        int curResult = INT_MIN;
        vector<int> prevMinState(4, INT_MAX);

        int cntA, cntB, prevCntA, prevCntB;
        cntA = cntB = prevCntA = prevCntB = 0;

        int l = -1;
        int r = 0;

        while (r < s.size()){
            cntA += (s[r] == a);
            cntB += (s[r] == b);
            
            while (r - l >= k && cntA - prevCntA >= 1 && cntB - prevCntB >= 2){
                int leftState = getState(prevCntA, prevCntB);

                prevMinState[leftState] = min(prevMinState[leftState], prevCntA - prevCntB);

                l++;
                prevCntA += (s[l] == a);
                prevCntB += (s[l] == b);
            }

            int rightState = getState(cntA, cntB);
            int leftState = rightState ^ 2;

            if (prevMinState[leftState] != INT_MAX){
                curResult = max(curResult, (cntA - cntB) - prevMinState[leftState]);
            }

            r++;
        }

        return curResult;
    }

    int getState(int cntA, int cntB){
        int parityA = cntA % 2;
        int parityB = cntB % 2;

        if (parityA == 0 && parityB == 0)   return 0;
        if (parityA == 0 && parityB == 1)   return 1;
        if (parityA == 1 && parityB == 0)   return 2;
        return 3;
    }
};