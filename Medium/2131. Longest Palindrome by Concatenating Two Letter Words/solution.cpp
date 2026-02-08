class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string, int> myMap;
        
        for (string s : words){
            myMap[s]++;
        }
        
        int result = 0;
        
        bool flag = false;
        
        for (int i = 0; i < words.size(); i++){
            
            if (myMap[words[i]] == 0)   continue;
            
            string rev = words[i];
            swap(rev[0], rev[1]);
            
            if (myMap.find(rev) != myMap.end() && myMap[rev] != 0 && words[i] != rev){
                result += 4;
                myMap[words[i]]--;
                myMap[rev]--;
            }
            else if (words[i] == rev){
                if (myMap[rev] % 2 != 0){
                    flag = true;
                    myMap[rev]--;
                }
                result += myMap[rev] * 2;
                myMap[rev] = 0;
            }
        }
        
        if (flag)   result += 2;
        
        return result;
    }
};