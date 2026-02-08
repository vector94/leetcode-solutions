class Solution {
public:
    
    bool isEqual(vector<int> &a, vector<int> &b){
        for (int i = 0; i < 26; i++){
            if (a[i] != b[i])   return false;
        }
        return true;
    }
    
    vector<int> findAnagrams(string s, string p) {
        
        if (p.size() > s.size())    return vector<int>();
        
        vector<int> pCnt(26, 0), sCnt(26, 0);
        
        for (char ch : p){
            pCnt[ch - 'a']++;
        }
           
        vector<int> result;
        
        for (int i = 0; i < s.size(); i++){
            if (i < p.size()){
                sCnt[s[i] - 'a']++;
            }
            else{
                if (isEqual(sCnt, pCnt)){
                    result.push_back(i - p.size());
                }
                sCnt[s[i - p.size()] - 'a']--;
                sCnt[s[i] - 'a']++;
            }
        }
        
        if (isEqual(sCnt, pCnt)){
            result.push_back(s.size() - p.size());
        }
        
        return result;
    }
};