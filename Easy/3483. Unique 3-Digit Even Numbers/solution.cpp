class Solution {
public:
    int Set(int num, int pos){
        return num | (1 << pos);
    }

    int Reset(int num, int pos){
        return num & ~(1 << pos);
    }

    bool Check(int num, int pos){
        return (bool) (num & (1 << pos));
    }

    int totalNumbers(vector<int>& digits) {
        set<int> mySet;
        solve(0, 0, 0, digits, mySet);

        return mySet.size();
    }

    void solve(int mask, int cnt, int num, vector<int>& digits, set<int>& mySet){
        if (cnt == 3){
            if (num % 2 == 0) mySet.insert(num);
            return;
        }

        for (int i = 0; i < digits.size(); i++){
            if (!Check(mask, i)){
                if (cnt == 0 && digits[i] == 0) continue;

                solve(Set(mask, i), cnt + 1, num * 10 + digits[i], digits, mySet);
            }
        }
    }
};