class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        int res = 0;
        for (auto x : stones){
            for (auto y : jewels){
                if (x == y){
                    res++;
                    break;
                }
            }
        }
        return res;
    }
};