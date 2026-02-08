class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> result;
        if (s.size() < p.size())    return result;
        
        vector<int> cntS(26, 0), cntP(26, 0);
        
        for (char ch : p){
            cntP[ch - 'a']++;
        }
        
        for (int i = 0; i < p.size(); i++){
            cntS[s[i] - 'a']++;
        }
        
        for (int i = p.size(); i < s.size(); i++){
            if (cntS == cntP){
                result.push_back(i - p.size());
            }
            cntS[s[i - p.size()] - 'a']--;
            cntS[s[i] - 'a']++;
        }
        
        if (cntS == cntP)   result.push_back(s.size() - p.size());
        return result;
    }
};