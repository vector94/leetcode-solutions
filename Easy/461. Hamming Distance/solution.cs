public class Solution {
    public int HammingDistance(int x, int y) {
        
        int xor = (x ^ y);
        int result = 0;
        
        while (xor > 0){
            if (xor % 2 == 1)   result++;
            xor /= 2;
        }
        
        return result;
    }
}