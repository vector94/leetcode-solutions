class Solution {
public:
    bool isIsomorphic(string s, string t) {
        map<char, char> myMap;
        map<char, bool> mapped;
        
        for (int i = 0; i < s.size(); i++){
            if (myMap.find(s[i]) == myMap.end()){
                if (mapped[t[i]] == false){
                    myMap[s[i]] = t[i];
                    mapped[t[i]] = true;
                }
                else{
                    return false;
                }
            }
            else if (myMap[s[i]] != t[i]){
                return false;
            }
        }
    
        return true;
    }
};