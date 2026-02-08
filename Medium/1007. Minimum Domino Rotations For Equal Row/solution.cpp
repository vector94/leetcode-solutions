class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int result = INT_MAX;
        
        int missingT, missingB;
        missingT = missingB = 0;
        
        for (int i = 0; i < tops.size(); i++){
            if (tops[i] != tops[0] && bottoms[i] != tops[0]){
                break;
            }
            if (tops[i] != tops[0])     missingT++;
            if (bottoms[i] != tops[0])  missingB++;
            if (i == tops.size() - 1)   return min(missingT, missingB);
        }
        
        missingT = missingB = 0;
        
        for (int i = 0; i < tops.size(); i++){
            if (tops[i] != bottoms[0] && bottoms[i] != bottoms[0]){
                break;
            }
            if (tops[i] != bottoms[0])     missingT++;
            if (bottoms[i] != bottoms[0])  missingB++;
            if (i == tops.size() - 1)   return min(missingT, missingB);
        }
        
        return -1;
    }
};