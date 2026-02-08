class Solution {
public:
    
    int executionHelper(int &n, vector<int>& startPos, string &s, int idx){
        int x = startPos[0];
        int y = startPos[1];
        
        int cnt = 0;
        
        while (idx < s.size()){
            if (s[idx] == 'L'){
                y--;
            }
            else if (s[idx] == 'R'){
                y++;
            }
            else if (s[idx] == 'U'){
                x--;
            }
            else{
                x++;
            }
            if (x >= 0 && x <= n - 1 && y >= 0 && y <= n - 1){
                cnt++;
            }
            else{
                break;
            }
            idx++;
        }
        
        return cnt;
    }
    
    vector<int> executeInstructions(int n, vector<int>& startPos, string s) {
        vector<int> result;
        for (int i = 0; i < s.size(); i++){
            result.push_back(executionHelper(n, startPos, s, i));
        }
        return result;
    }
};