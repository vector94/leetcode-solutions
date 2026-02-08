class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int cntB = 0;
        for (int i = 0; i < k; i++){
            if (blocks[i] == 'B')   cntB++;
        }

        int maxB = cntB;
        int left = 0;
        int right = k;

        while (right < blocks.size()){
            if (blocks[left] == 'B')    cntB--;
            if (blocks[right] == 'B')   cntB++;

            if (cntB > maxB)    maxB = cntB;
            left++;
            right++;
        }

        return k - maxB;
    }
};