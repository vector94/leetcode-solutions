class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> hashMap;
        for (char ch : s){
            hashMap[ch]++;
        }
        int hasOdd = false;
        int result = 0;
        for (auto it : hashMap){
            hasOdd |= it.second & 1;
            result += it.second / 2;
        }
        result *= 2;
        result += hasOdd;
        return result;
    }
};