class Solution {
public:
    string vowels = "aeiou";

    int getKCount(int left, int right, vector<vector<int> > &prefixSum){
        int aCount = prefixSum[0][right] - prefixSum[0][left - 1];
        int eCount = prefixSum[1][right] - prefixSum[1][left - 1];
        int iCount = prefixSum[2][right] - prefixSum[2][left - 1];
        int oCount = prefixSum[3][right] - prefixSum[3][left - 1];
        int uCount = prefixSum[4][right] - prefixSum[4][left - 1];

        if (aCount == 0 || eCount == 0 || iCount == 0 || oCount == 0 || uCount == 0){
            return -1;
        }

        int kCount = (right - left + 1) - (aCount + eCount + iCount + oCount + uCount);
        return kCount;
    }

    long long atLeastK(int k, int N, vector<vector<int> > &prefixSum){
        long long res = 0;
        int l = 1, r = 1;
        while (r <= N) {
            int kCount = getKCount(l, r, prefixSum);
            if (kCount >= k){
                res += N - r + 1;
                l++;
            }
            else{
                r++;
            }
        }

        return res;
    }

    long long countOfSubstrings(string word, int k) {
        int N = word.size();

        vector<vector<int>> prefixSum(5, vector<int>(N + 1, 0));

        for (int i = 1; i <= N; i++){
            char curChar = word[i - 1];

            for (int j = 0; j < 5; j++) {
                prefixSum[j][i] = prefixSum[j][i - 1];
            }
            
            for (int j = 0; j < 5; j++) {
                if (curChar == vowels[j]) {
                    prefixSum[j][i]++;
                    break;
                }
            }
        }

        return atLeastK(k, N, prefixSum) - atLeastK(k + 1, N, prefixSum);
    }
};