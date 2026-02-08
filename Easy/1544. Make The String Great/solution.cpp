class Solution {
public:
    string makeGood(string s) {
        stack<char> myStack;
        
        for (int i = 0; i < s.size(); i++){
            if (myStack.empty()){
                myStack.push(s[i]);
                continue;
            }
            char topChar = myStack.top();
            
            if (isupper(topChar)){
                if (tolower(topChar) == s[i]){
                    myStack.pop();
                }
                else{
                    myStack.push(s[i]);
                }
            }
            else{
                if (toupper(topChar) == s[i]){
                    myStack.pop();
                }
                else{
                    myStack.push(s[i]);
                }
            }
        }
        
        string ans;
        while (!myStack.empty()){
            ans.push_back(myStack.top());
            myStack.pop();
        }
        
        reverse(ans.begin(), ans.end());
        
        return ans;
    }
};