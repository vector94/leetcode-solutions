class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<pair<int, int> > ST;
        int result = 0;
        
        for (int i = 0; i < heights.size(); i++){
            if (ST.empty() || ST.top().first < heights[i]){
                ST.push({heights[i], i});
            }
            else{
                int maxLeft = i;
                while (!ST.empty() && ST.top().first >= heights[i]){
                    int curHeight = ST.top().first;
                    int curLeft = ST.top().second;
                    maxLeft = min(maxLeft, curLeft);
                    ST.pop();
                    
                    result = max(result, curHeight * (i - curLeft));
                }
                ST.push({heights[i], maxLeft});
            }
        }
        
        while (!ST.empty()){
            int curHeight = ST.top().first;
            int width = heights.size() - ST.top().second;
            result = max(result, curHeight * width);
            ST.pop();
        }
        
        return result;
    }
};