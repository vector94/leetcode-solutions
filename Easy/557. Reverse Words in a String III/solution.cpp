class Solution {
public:
    
    void reverseHelper(string &s, int start, int end){
        while (start < end){
            swap(s[start++], s[end--]);
        }
    }
    
    string reverseWords(string s) {
        
        int start;
        bool flag = false;
        
        for (int i = 0; i < s.size(); i++){
            if (s[i] == ' '){
                if (flag){
                    reverseHelper(s, start, i - 1);
                    flag = false;
                }
            }
            else{
                if (!flag){
                    flag = true;
                    start = i;
                }
            }
        }
        
        if (flag){
            reverseHelper(s, start, s.size() - 1);
        }
                
        return s; 
    }
};