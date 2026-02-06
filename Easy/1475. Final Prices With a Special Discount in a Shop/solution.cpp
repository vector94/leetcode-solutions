class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int N = prices.size();
        vector<int> result(N);

        stack<pair<int, int>> myStack;
        for (int i = 0; i < prices.size(); i++){
            while (!myStack.empty() && myStack.top().first >= prices[i]){
                pair<int, int> prevPrice = myStack.top();
                myStack.pop();

                result[prevPrice.second] = prevPrice.first - prices[i];
            }

            myStack.push({prices[i], i});
        }

        while (!myStack.empty()){
            result[myStack.top().second] = myStack.top().first;
            myStack.pop();
        }

        return result;
    }
};