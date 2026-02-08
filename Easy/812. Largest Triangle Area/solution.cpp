class Solution {
public:
    double largestTriangleArea(vector<vector<int>>& points) {
        int N = points.size();
        double area = 0.0;

        for (int i = 0; i < N; i++){
            for (int j = i + 1; j < N; j++){
                for (int k = j + 1; k < N; k++){
                    double x1 = points[i][0];
                    double y1 = points[i][1];

                    double x2 = points[j][0];
                    double y2 = points[j][1];

                    double x3 = points[k][0];
                    double y3 = points[k][1];

                    double a = hypot(x2 - x1, y2 - y1);
                    double b = hypot(x3 - x2, y3 - y2);
                    double c = hypot(x3 - x1, y3 - y1);

                    double s = (a + b + c) * 0.5;
                    
                    double heronArea = sqrt(s * (s - a) * (s - b) * (s - c));

                    area = max(area, heronArea);
                }
            }
        }

        return area;
    }
};