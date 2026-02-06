class Solution {
public:
    int countCollisions(string directions) {
        int ans = 0;

        stack<char>myStack;

        for (char d : directions){
            if (d == 'R'){
                myStack.push('R');
            }
            else if (d == 'L'){
                if (myStack.empty())    continue;
                if (myStack.top() == 'R'){
                    ans += 2;
                    myStack.pop();

                    while (!myStack.empty() && myStack.top() == 'R'){
                        ans++;
                        myStack.pop();
                    }

                    myStack.push('S');
                }
                else{
                    ans++;
                }
            }
            else{
                while (!myStack.empty() && myStack.top() == 'R'){
                    ans++;
                    myStack.pop();
                }

                while (!myStack.empty()){
                    myStack.pop();
                }
                myStack.push('S');
            }
        }

        return ans;
    }
};