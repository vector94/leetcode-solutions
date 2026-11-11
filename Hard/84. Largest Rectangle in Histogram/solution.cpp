class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        vector<pair<int, int>> myStack;

        int result = 0;
        for (int i = 0; i < heights.size(); i++){
            if (myStack.empty() || myStack.back().first <= heights[i]){
                myStack.push_back({heights[i], i});
                continue;
            }

            int first_bar = myStack.back().first;
            int first_idx = myStack.back().second;
            result = max(result, first_bar);
            myStack.pop_back();
            int last_idx = first_idx;

            while (!myStack.empty() && myStack.back().first > heights[i]){
                int cur_bar = myStack.back().first;
                int cur_idx = myStack.back().second;
                result = max(result, cur_bar * ((first_idx - cur_idx) + 1));
                last_idx = cur_idx;
                myStack.pop_back();
            }

            myStack.push_back({heights[i], last_idx});
            if (i != last_idx){
                myStack.push_back({heights[i], i});
            }
        }

        int top_idx = myStack.back().second;
        while (!myStack.empty()){
            int cur_bar = myStack.back().first;
            int cur_idx = myStack.back().second;
            myStack.pop_back();

            result = max(result, cur_bar * ((top_idx - cur_idx) + 1));
        }

        return result;
    }
};