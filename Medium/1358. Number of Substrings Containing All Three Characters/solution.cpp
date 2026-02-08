class Solution {
public:
    int numberOfSubstrings(string s) {
        int res = 0;

        int left, right;
        left = right = 0;

        int aCount, bCount, cCount;
        aCount = bCount = cCount = 0;
        int N = s.size();

        while (left < N && right < N){
            if (s[right] == 'a')    aCount++;
            else if (s[right] == 'b')   bCount++;
            else if (s[right] == 'c')   cCount++;

            while (aCount > 0 && bCount > 0 && cCount > 0){
                res += N - right;
                
                if (s[left] == 'a') aCount--;
                else if (s[left] == 'b')    bCount--;
                else if (s[left] == 'c')    cCount--;
                left++;
            }
            
            right++;
        }

        return res;
    }
};