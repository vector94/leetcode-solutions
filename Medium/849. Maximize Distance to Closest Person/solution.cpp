class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int n = seats.size();
        vector<int> leftPerson(n), rightPerson(n);
        
        int left = -2e5;
        
        for (int i = 0; i < n; i++){
            if (seats[i] == 1){
                left = i;
            }
            leftPerson[i] = left;
        }
        
        int right = 2e5;
        for (int i = n - 1; i >= 0; i--){
            if (seats[i] == 1){
                right = i;
            }
            rightPerson[i] = right;
        }
        
        int maxDist = 0;
        
        for (int i = 0; i < n; i++){
            if (seats[i] == 0){
                int dist = min(i - leftPerson[i], rightPerson[i] - i);
                if (maxDist < dist){
                    maxDist = dist;
                }
            }
        }
        
        return maxDist;
    }
};