class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int prev = 0;
        int ans = 0;

        for (int i = 0; i < bank.size(); i++){
            int laser = 0;
            for (int c : bank[i]){
                if (c == '1') laser++;
            }

            if (laser > 0){
                ans += prev * laser;
                prev = laser;
            }
        }

        return ans;
    }
};