class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> hashMap(26, 0);
        
        for (char ch : s){
            hashMap[ch - 'a']++;
        }
        
        for (int i = 0; i < s.size(); i++){
            if (hashMap[s[i] - 'a'] == 1){
                return i;
            }
        }
        
        return -1;
    }
};