class Solution {
public:

    bool isSameLine(vector<int> &point1, vector<int> &point2, vector<int> &point3){
        return (point3[1] - point1[1]) * (point2[0] - point1[0]) == (point2[1] - point1[1]) * (point3[0] - point1[0]);
    }

    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        if (n <= 2) return n;
        
        int result = 2;
        
        for (int i = 0; i < n; i++){
            for (int j = i + 1; j < n; j++){
                int total = 2;
                for (int k = 0; k < n; k++){
                    if (k != i && k != j){
                        if (isSameLine(points[i], points[j], points[k])){
                            total++;
                        }
                    }
                }
                result = max(result, total);
            }
        }

        return result;
    }
};

