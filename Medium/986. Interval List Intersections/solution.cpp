class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        int n = firstList.size();
        int m = secondList.size();
        
        int i, j;
        i = j = 0;
        
        vector<vector<int> > result;
        
        while (i < n && j < m){
            int left = max(firstList[i][0], secondList[j][0]);
            int right = min(firstList[i][1], secondList[j][1]);
            
            if (left <= right){
                result.push_back({left, right});
            }
            
            if (firstList[i][1] < secondList[j][1]){
                i++;
            }
            else{
                j++;
            }
        }
        
        return result;
    }
};