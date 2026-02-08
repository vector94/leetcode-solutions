class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int x = 0;
        
        for (string s : operations){
            if (s[0] == '+' || s.back() == '+') x++;
            else    x--;
        }
        
        return x;
    }
};