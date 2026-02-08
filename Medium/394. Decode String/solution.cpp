class Solution {
public:
    string decodeString(string s) {
        
        stack<string> myStack;
        
        for (int i = 0; i < s.size(); i++){
            //cout << "here" << myStack.top() << " " << i << endl;
            if (isdigit(s[i])){
                string num;
                
                while (isdigit(s[i])){
                    num += s[i];
                    i++;
                }
                
                cout << num << endl;
                
                myStack.push(num);
            }
            else if (isalpha(s[i])){
                string curString;
                
                while (i < s.size() && isalpha(s[i])){
                    curString += s[i];
                    i++;
                }
                
                cout << curString << endl;
                
                if (!myStack.empty() && isalpha(myStack.top().back())){
                    string newString = myStack.top();
                    myStack.pop();
                    newString += curString;
                    myStack.push(newString);
                }
                else{
                    myStack.push(curString);
                }
                
                i--;
            }
            else{
                string curString = myStack.top();
                myStack.pop();
                
                int cnt = stoi(myStack.top());
                
                cout << curString << " " << cnt << endl;
                
                myStack.pop();
                string newString;
                
                while (cnt--){
                    newString += curString;
                }
                
                //cout << newString << " " << i << endl;
                
                if (!myStack.empty() && isalpha(myStack.top().back())){
                    curString = myStack.top();
                    myStack.pop();
                    curString += newString;
                    myStack.push(curString);
                }
                else{
                    myStack.push(newString);
                }
                
            }
        }
        
        return myStack.top();
    }
};