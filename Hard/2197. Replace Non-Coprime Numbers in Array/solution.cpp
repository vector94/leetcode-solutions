class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        stack<int> myStack;

        for (int i = 0; i < nums.size(); i++){
            int x = nums[i];

            while (!myStack.empty()){
                int y = myStack.top();

                if (__gcd(x, y) > 1){
                    myStack.pop();
                    x = lcm(x, y);
                }
                else{
                    break;
                }
            }

            myStack.push(x);
        }

        vector<int> result;
        while (!myStack.empty()){
            result.push_back(myStack.top());
            myStack.pop();
        }

        reverse(result.begin(), result.end());

        return result;
    }

    int lcm(int a, int b) {
    return (a / __gcd(a, b)) * b;
}
};