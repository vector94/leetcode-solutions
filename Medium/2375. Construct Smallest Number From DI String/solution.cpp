class Solution {
public:
    long long setBit(long long num, int idx){
        return num | (1LL << idx);
    }

    long long resetBit (long long num, int idx){
        return num & ~(1LL << idx);
    }

    bool checkBit (long long num, int idx){
        return (bool)(num & (1LL << idx));
    }

    string ans = "9999999999";
    void checkSmallestString(string a) {
        if (a < ans) ans = a;
    }

    string smallestNumber(string pattern) {
        string cur = "";
        long long checkMap =  0;

        backtrack(0, checkMap, cur, pattern);

        return ans;
    }

    void backtrack(int idx, long long checkMap, string cur, string pattern){        
        if (idx == pattern.size() + 1){
            checkSmallestString(cur);
            return;
        }

        if (idx == 0){
            for (int i = 0; i < 9; i++){
                cur.push_back('1' + i);
                backtrack(idx + 1, setBit(checkMap, i), cur, pattern);
                cur.pop_back();
            }
        }
        else{
            for (int i = 0; i < 9; i++){
                if (checkBit(checkMap, i)){
                    continue;
                }

                if (pattern[idx - 1] == 'I' && ('1' + i) > cur[idx - 1]){
                    cur.push_back('1' + i);
                    backtrack(idx + 1, setBit(checkMap, i), cur, pattern);
                    cur.pop_back();
                }
                else if (pattern[idx - 1] == 'D' && ('1' + i) < cur[idx - 1]){
                    cur.push_back('1' + i);
                    backtrack(idx + 1, setBit(checkMap, i), cur, pattern);
                    cur.pop_back();
                }
            }
        }
    }

};