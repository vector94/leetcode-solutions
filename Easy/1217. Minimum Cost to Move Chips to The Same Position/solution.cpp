class Solution {
public:
    int minCostToMoveChips(vector<int>& p) {
        int even, odd;
        even = odd = 0;
        for (int i = 0; i < p.size(); i++){
            if (p[i] % 2 == 0) even++;
            else odd++;
        }
        if (even == 0 || odd == 0) return 0;
        else return min(even, odd);

    }
};