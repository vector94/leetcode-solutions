class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s2.size() < s1.size())  return false;
        
        vector<int> goal(26, 0), have(26, 0);
                
        for (int i = 0; i < s1.size(); i++){
            goal[s1[i] - 'a']++;
            have[s2[i] - 'a']++;
        }
        if (goal == have)   return true;
        
        for (int i = s1.size(); i < s2.size(); i++){
            have[s2[i - s1.size()] - 'a']--;
            have[s2[i] - 'a']++;
            
            if (goal == have)   return true;
        }
        
        return false;
    }
};