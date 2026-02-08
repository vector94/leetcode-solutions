class Solution {
public:
    double new21Game(int n, int k, int maxPts) {
        vector<double> p(n + 1, 0.0);
        p[0] = 1;
        double curProbSum = (k == 0) ? 0 : 1;

        for (int i = 1; i <= n; i++){
            p[i] = curProbSum / maxPts;

            if (i < k){
                curProbSum += p[i];
            }

            if (i - maxPts >= 0 && i - maxPts < k){
                curProbSum -= p[i - maxPts];
            }
        }

        return accumulate(begin(p) + k, end(p), 0.0);
    }
};