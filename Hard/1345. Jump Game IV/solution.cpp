class Solution {
public:
    int minJumps(vector<int>& arr) {
        map<int, vector<int> > myMap;
        
        int n = arr.size();
        for (int i = 0; i < n; i++){
            myMap[arr[i]].push_back(i);
        }
        
        queue<int> myQueue;
        int result = 0;
        
        vector<bool> mark(n, false);
        
        myQueue.push(0);
        mark[0] = true;
        
        while (!myQueue.empty()){
            
            int cnt = myQueue.size();
            
            for (int i = 0; i < cnt; i++){
                
                int cur = myQueue.front();
                myQueue.pop();
                
                if (cur == n - 1){
                    return result;
                }
                
                if (cur - 1 >= 0 && !mark[cur - 1]){
                    myQueue.push(cur - 1);
                    mark[cur - 1] = true;
                }
                if (cur + 1 < n && !mark[cur + 1]){
                    myQueue.push(cur + 1);
                    mark[cur + 1] = true;
                }
                
                for (int next : myMap[arr[cur]]){
                    if (!mark[next]){
                        myQueue.push(next);
                        mark[next] = true;
                    }
                }
                
                myMap[arr[cur]].clear();
            }
            
            result++;
        }
        
        return result;
    }
};