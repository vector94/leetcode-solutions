class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string, int> myMap;
        for (string w: words){
            myMap[w]++;
        }

        int result = 0;
        bool flag = false;

        for (string w: words){
            if (myMap[w] == 0){
                continue;
            }

            string rev = w;
            swap(rev[0], rev[1]);
            
            if (w == rev){
                if (myMap[w] & 1){
                    flag = true;
                    myMap[w]--;
                }

                result += myMap[w] * 2;
            }
            else if (myMap.find(rev) != myMap.end() && myMap[rev] > 0){
                result += min(myMap[w], myMap[rev]) * 4;
            }

            myMap[w] = 0;
        }

        if (flag){
            result += 2;
        }

        return result;
    }
};