class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        
        sort(ransomNote.begin(), ransomNote.end());
        
        sort(magazine.begin(), magazine.end());
        
        int i, j;
        i = j = 0;
        
        while (true){
            if (i == ransomNote.size()) return true;
            if (j == magazine.size())   return false;
            
            if (ransomNote[i] == magazine[j]){
                i++;
                j++;
            }
            else{
                j++;
            }
        }
        
        return false;
    }
};