class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        
        int i = 0, j = people.size() - 1;
        int result = 0;
        
        while (i <= j){
            result++;
            if (people[i] + people[j] <= limit){
                i++;
            }
            j--;
        }
        
        return result;
    }
};