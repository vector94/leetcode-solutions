class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        vector<int> inDegree(numCourses, 0);
        
        for (int i = 0; i < prerequisites.size(); i++){
            graph[prerequisites[i][1]].push_back(prerequisites[i][0]);
            inDegree[prerequisites[i][0]]++;
        }
        
        queue<int> myQueue;
        for (int i = 0; i < numCourses; i++){
            if (inDegree[i] == 0){
                myQueue.push(i);
            }
        }
        
        while (!myQueue.empty()){
            int curCourse = myQueue.front();
            myQueue.pop();
            
            
            for (int nextCourse: graph[curCourse]){
                inDegree[nextCourse]--;
                
                if (inDegree[nextCourse] == 0){
                    myQueue.push(nextCourse);
                }
            }
        }
        
        for (int i = 0; i < numCourses; i++){
            if (inDegree[i] != 0)   return false;
        }
        return true;
    }
};