class Solution {
public:
    int nthMagicalNumber(int n, int a, int b) {
        int mod = 1e9 + 7;
        int lcm = (a * b) / __gcd(a, b);
        
        
        long long lo = 2;
        long long hi = (long long)n * min(a, b);
        
        long result;
        
        while (lo <= hi){
            long long mid = lo + (hi - lo) / 2;
            
            if (mid / a + mid / b - mid / lcm >= n){
                result = mid;
                hi = mid - 1;
            }
            else{
                lo = mid + 1;
            }
        }
        
        return (int) (result % mod);
    }
};