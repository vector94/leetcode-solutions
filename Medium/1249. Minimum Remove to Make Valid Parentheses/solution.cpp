class Solution {
public:
    string minRemoveToMakeValid(string s) {
        vector<pair<char, int> > myStack;
        for (int i = 0; i < s.size(); i++){
            if (s[i] == '('){
                myStack.push_back({'(', i});
            }
            else if (s[i] == ')'){
                if (!myStack.empty() && myStack.back().first == '(')   myStack.pop_back();
                else    myStack.push_back({')', i});
            }
        }
        
        string result;
        int i = 0;
        for (int j = 0; j < s.size(); j++){
            if (i < myStack.size() && myStack[i].second == j){
                i++;
                continue;
            }
            result.push_back(s[j]);
        }
        return result;
    }
};