class Solution {
public:
    int minMoves(int target, int maxDoubles) {
        int result = 0;
        while (maxDoubles && target > 1){
            if (target & 1){
                target--;
            }
            else{
                target /= 2;
                maxDoubles--;
            }
            result++;
        }
        
        result += target - 1;
        
        return result;
    }
};