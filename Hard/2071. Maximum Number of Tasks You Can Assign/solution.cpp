class Solution {
public:
    int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) {
        sort(tasks.begin(), tasks.end());
        sort(workers.begin(), workers.end());

        int N = tasks.size();
        int M = workers.size();

        int low = 0;
        int high = min(N, M);

        int ans = 0;
        while (low <= high){
            int mid = (low + high) / 2;
            if (check(mid, tasks, workers, pills, strength)){
                ans = mid;
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }

        return ans;
    }

    bool check(int cnt, vector<int>& tasks, vector<int>& workers, int pills, int strength){
        multiset<int> mySet;
        for (int i = workers.size() - cnt; i < workers.size(); i++){
            mySet.insert(workers[i]);
        }

        for (int i = cnt - 1; i >= 0; i--){
            auto it = prev(mySet.end());
            if (*it >= tasks[i]){
                mySet.erase(it);
            }
            else{
                if (pills <= 0){
                    return false;
                }
                pills--;
                auto it = mySet.lower_bound(tasks[i] - strength);
                
                if (it != mySet.end()){
                    mySet.erase(it);
                }
                else{
                    return false;
                }
            }
        }
        return true;
    }
};