class Solution {
public:
    int maxDifference(string s) {
        vector<int> cnt(26, 0);

        for (char ch : s){
            cnt[ch - 'a']++;
        }

        int maxOdd, minEven;
        maxOdd = 0; 
        minEven = INT_MAX;

        for (int i = 0; i < 26; i++){
            if (cnt[i] == 0)    continue;
            if (cnt[i] & 1){
                maxOdd = max(maxOdd, cnt[i]);
            }
            else{
                minEven = min(minEven, cnt[i]);
            }
        }

        return maxOdd - minEven;
    }
};