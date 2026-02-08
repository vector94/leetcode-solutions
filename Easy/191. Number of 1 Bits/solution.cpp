class Solution {
public:
    int hammingWeight(long long int n) {
        int ret = 0;
        long long int mask = 1;
        for (int i = 0; i < 32; i++){
            if (n & mask){
                ret++;
            }
            mask <<= 1;
        }
        return ret;
    }
};