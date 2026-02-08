class Solution {
public:
    long long minimumHealth(vector<int>& damage, int armor) {
        long long totalDamage = 0;
        long long maxDamage = 0;
        for (long long d : damage){
            totalDamage += d;
            maxDamage = max(maxDamage, d);
        }
        return totalDamage - min((long long)armor, maxDamage) + 1;
    }
};