class Solution {
public:
    
    bool backtrack(int index, vector<int> &match, vector<int> &sides, int sideLength){
        if (index == match.size()){
            return (sides[0] == sides[1] && sides[1] == sides[2] && sides[2] == sides[3]);
        }
        
        for (int i = 0; i < 4; i++){
            if (sides[i] + match[index] <= sideLength){
                sides[i] += match[index];
                if (backtrack(index + 1, match, sides, sideLength)){
                    return true;
                }
                sides[i] -= match[index];
            }
        }
        
        return false;
    }
    
    bool makesquare(vector<int>& match) {
        if (match.size() < 4)   return false;
        int sum = 0;
        for (int m : match){
            sum += m;
        }
        if (sum % 4 != 0)   return false;
        vector<int> sides(4, 0);
        sort(match.begin(), match.end(), greater<int>());
        return backtrack(0, match, sides, sum / 4);
    }
};