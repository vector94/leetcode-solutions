class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& preq) {
        vector<vector<int> > graph(numCourses, vector<int>());
        vector<int> inDegree(numCourses, 0);
        
        for (int i = 0; i < preq.size(); i++){
            graph[preq[i][1]].push_back(preq[i][0]);
            inDegree[preq[i][0]]++;
        }
        
        queue<int> myQueue;
        
        for (int i = 0; i < numCourses; i++){
            if (inDegree[i] == 0){
                myQueue.push(i);
            }
        }
        
        vector<int> result;
        
        while (!myQueue.empty()){
            int cur = myQueue.front();
            myQueue.pop();
            result.push_back(cur);
            
            for (int next : graph[cur]){
                inDegree[next]--;
                if (inDegree[next] == 0){
                    myQueue.push(next);
                }
            }
        }
        
        if (result.size() != numCourses)    result.clear();
        return result;
    }
};