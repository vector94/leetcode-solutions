class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int ans = 0;

        for (int i = low; i <= high; i++){
            if (i > 9 && i < 100){
                int left = i / 10;
                int right = i % 10;
                if (left == right)  ans++;
            }
            else if (i > 999 && i < 10000){
                int left = i / 1000 + (i / 100) % 10;
                int right = (i / 10) % 10 + i % 10;
                if (left == right)  ans++;
            }
        }

        return ans;
    }
};