class Solution {
public:
    string stringShift(string s, vector<vector<int>>& shift) {
        int finalShift = 0;
        for (int i = 0; i < shift.size(); i++){
            finalShift += shift[i][0] == 0 ? -shift[i][1] : shift[i][1];
        }
        string result;
        if (finalShift < 0){
            finalShift = abs(finalShift) % s.size();
            result = s.substr(finalShift, s.size() - finalShift) + s.substr(0, finalShift);
        }
        else{
            finalShift %= s.size();
            result = s.substr(s.size() - finalShift, finalShift) + s.substr(0, s.size() - finalShift);
        }
        return result;
    }
};