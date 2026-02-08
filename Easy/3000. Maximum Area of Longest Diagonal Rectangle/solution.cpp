class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int area = 0;
        int diagonal = 0;
        for (int i = 0; i < dimensions.size(); i++){
            int rootDiagonal = dimensions[i][0] * dimensions[i][0] + dimensions[i][1] * dimensions[i][1];
            int curArea = dimensions[i][0] * dimensions[i][1];

            if (rootDiagonal > diagonal){
                area = curArea;
                diagonal = rootDiagonal;
            }
            else if (rootDiagonal == diagonal){
                area = max(area, curArea);
            }
        }

        return area;
    }
};