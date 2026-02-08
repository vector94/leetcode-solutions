class Solution {
public:

    int rotate(int n){
        if (n == 2 || n == 3 || n == 4 || n == 5 || n == 7) return -1;
        if (n == 6) return 9;
        if (n == 9) return 6;
        return n;
    }

    bool confusingNumber(int n) {
        bool confusing = false;
        bool invalid = false;

        int actualNumber = n;
        int rotatedNumber = 0;

        while (n){
            if (rotate(n % 10) == -1)   return false;
            rotatedNumber =  rotatedNumber * 10 + (rotate(n % 10));
            cout << rotatedNumber << endl;
            n /= 10;
        }

        return actualNumber != rotatedNumber;
    }
};