class Solution {
public:
    int possibleStringCount(string word) {
        int ans = 1;
        for (int i = 1; i < word.size(); i++){
            int cnt = 0;
            while (i < word.size() && word[i] == word[i - 1]){
                cnt++;
                i++;
            }

            ans += cnt;
        }

        return ans;
    }
};