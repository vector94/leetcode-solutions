class TaskManager {
public:
    unordered_map<int, int> taskToUser;
    unordered_map<int, int> taskToPriority;
    priority_queue<pair<int, int>> myPQ;

    TaskManager(vector<vector<int>>& tasks) {
        for (int i = 0; i < tasks.size(); i++){
            int userId = tasks[i][0];
            int taskId = tasks[i][1];
            int priority = tasks[i][2];

            taskToUser[taskId] = userId;
            taskToPriority[taskId] = priority;
            myPQ.push({priority, taskId});
        }
    }
    
    void add(int userId, int taskId, int priority) {
        taskToUser[taskId] = userId;
        taskToPriority[taskId] = priority;
        myPQ.push({priority, taskId});
    }
    
    void edit(int taskId, int newPriority) {
        taskToPriority[taskId] = newPriority;
        myPQ.push({newPriority, taskId});
    }
    
    void rmv(int taskId) {
        taskToUser[taskId] = -1;
        taskToPriority[taskId] = -1;
    }
    
    int execTop() {
        while (!myPQ.empty()){
            pair<int, int> topTask = myPQ.top();
            myPQ.pop();

            if (taskToPriority[topTask.second] == topTask.first){
                taskToPriority[topTask.second] = -1;
                return taskToUser[topTask.second];
            }
        }

        return -1;
    }
};

/**
 * Your TaskManager object will be instantiated and called as such:
 * TaskManager* obj = new TaskManager(tasks);
 * obj->add(userId,taskId,priority);
 * obj->edit(taskId,newPriority);
 * obj->rmv(taskId);
 * int param_4 = obj->execTop();
 */