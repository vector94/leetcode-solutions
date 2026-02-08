class Solution {
public:
    int minimumDeletions(string word, int k) {
        vector<int> freq(26, 0);
        for (char ch : word){
            freq[ch - 'a']++;
        }

        int ans = INT_MAX;
        for (int i = 0; i < 26; i++){
            ans = min(ans, getCurDiff(i, freq, k));
        }

        return ans;
    }

    int getCurDiff(int ch, vector<int>& freq, int k){
        int ret = 0;

        for (int i = 0; i < 26; i++){
            if (freq[i] == 0 || i == ch)   continue;

            if (freq[i] < freq[ch]){
                ret += freq[i];
            }
            else{
                int curDiff = freq[i] - freq[ch];
                if (curDiff > k){
                    ret += curDiff - k;
                }
            }
        }

        return ret;
    }
};