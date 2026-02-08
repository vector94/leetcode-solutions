class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char, int> > myStack;
        for (char ch : s){
            if (myStack.empty() || myStack.top().first != ch){
                myStack.push({ch, 1});
            }
            else{
                if (myStack.top().second == k - 1){
                    myStack.pop();
                }
                else{
                    pair<char, int> pii = myStack.top();
                    myStack.pop();
                    pii.second++;
                    myStack.push(pii);
                }
            }
        }
        string result;
        while (!myStack.empty()){
            char ch = myStack.top().first;
            int count = myStack.top().second;
            myStack.pop();
            while (count--){
                result.push_back(ch);
            }
        }
        reverse(result.begin(), result.end());
        return result;
    }
};