class Solution {
public:
    bool checkAlmostEquivalent(string word1, string word2) {
        map<char, int> m1, m2;
        for (char ch : word1){
            m1[ch]++;
        }
        for (char ch : word2){
            m2[ch]++;
        }
        
        for (char ch = 'a'; ch <= 'z'; ch++){
            if (abs(m1[ch] - m2[ch]) > 3){
                return false;
            }
        }
        return true;
    }
};