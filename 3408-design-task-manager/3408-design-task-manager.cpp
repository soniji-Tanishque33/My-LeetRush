class TaskManager {
public:
    map<pair<int, int>, int> user; // {priority, taskid} -> user
    map<int, int> prior; // task -> prioruty

    TaskManager(vector<vector<int>>& tasks) {
        for(auto& task: tasks) {
            int userid = task[0];
            int taskid = task[1];
            int pri= task[2];
            user[{pri, taskid}] = userid;
            prior[taskid] = pri;
        }
    }
    
    void add(int userId, int taskId, int priority) {
        user[{priority, taskId}] = userId;
        prior[taskId] = priority;
    }
    
    void edit(int taskId, int newPriority) {
        int prev_priority = prior[taskId];
        int userid = user[{prev_priority, taskId}];
        user.erase({prev_priority, taskId});
        prior[taskId] = newPriority;
        user[{newPriority, taskId}] = userid;
    }
    
    void rmv(int taskId) {
        int pri = prior[taskId];
        prior.erase(taskId);
        user.erase({pri, taskId});
    }
    
    int execTop() {
        if(user.size() == 0) return -1;
        int ans = user.rbegin()->second;
        int taskId = user.rbegin()->first.second;
        user.erase(prev(user.end()));
        prior.erase(taskId);
        return ans;
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