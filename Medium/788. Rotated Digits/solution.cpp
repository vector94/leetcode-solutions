class Solution {
public:
    int rotatedDigits(int n) {
        int ans = 0;

        for (int i = 1; i <= n; i++){
            bool flag = true;
            bool diff = false;

            int x = i;
            while (x){
                int rem = x % 10;

                if (rem == 3 || rem == 4 || rem == 7){
                    flag = false;
                    break;
                }

                if (rem == 2 || rem == 5 || rem == 6 || rem == 9){
                    diff = true;
                }

                x /= 10;
            }

            if (flag && diff)   ans++;
        }

        return ans;
    }
};