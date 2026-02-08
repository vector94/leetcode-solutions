class Solution {
public:
    string removeKdigits(string num, int k) {
        
        deque<int> myStack;
        for (char n : num){
            if (myStack.empty() || k == 0 || myStack.back() <= n - '0'){
                myStack.push_back(n - '0');
            }
            else{
                while (!myStack.empty() && myStack.back() > n - '0' && k){
                    myStack.pop_back();
                    k--;
                }
                myStack.push_back(n - '0');
            }
        }
        while (!myStack.empty() && k){
            myStack.pop_back();
            k--;
        }
        while (!myStack.empty() && myStack.front() == 0){
            myStack.pop_front();
        }
        
        string result = "";
        for (int n : myStack){
            result+=(n + '0');
        }
        if (result == ""){
            result = "0";
        }
        return result;
    }
};