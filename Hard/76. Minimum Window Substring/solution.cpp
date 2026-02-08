class Solution {
public:
    
    bool check(vector<int> &have, vector<int> &need){
        for (int i = 0; i < 100; i++){
            if (have[i] < need[i]){
                return false;
            }
        }
        return true;
    }
    
    string minWindow(string s, string t) {
        vector<int> need(100, 0), have(100, 0);
        
        for (char ch : t){
            need[ch - 'A']++;
        }
        
        int left, right;
        have[s[0] - 'A']++;
        left = 0, right = 1;
        
        int minLength = s.size() + 1;
        string result = "";
        
        while (true){
            bool ok = check(have, need);
            if (!ok && right == s.size()){
                break;
            }
            else if (ok){
                int curLength = right - left;
                if (minLength > curLength){
                    minLength = curLength;
                    result = s.substr(left, curLength);
                }
                have[s[left++] - 'A']--;
            }
            else{
                have[s[right++] - 'A']++;
            }
        }
        
        return result;
    }
};