class TaskManager {

    set<pair<int,int>>tasks; //tasks(id,priority)

    unordered_map<int,int>pri; //taskId,priority

    unordered_map<int,int>user; //taskId,userId 


public:
    TaskManager(vector<vector<int>>& task) {

        for(auto&v:task){

            int uId=v[0];
            int tId=v[1];
            int p=v[2];

            tasks.insert({-p,-tId});

            pri[tId]=p;

            user[tId]=uId;
        }
        
    }
    
    void add(int userId, int taskId, int priority) {

        tasks.insert({-priority,-taskId});

        pri[taskId]=priority;

        user[taskId]=userId;
        
    }
    
    void edit(int taskId, int newPriority) {

        int oldP=pri[taskId];

        tasks.erase({-oldP,-taskId});

        tasks.insert({-newPriority,-taskId});

        pri[taskId]=newPriority;
        
    }
    
    void rmv(int taskId) {

        int p=pri[taskId];

        tasks.erase({-p,-taskId});

        pri.erase(taskId);

        user.erase(taskId);


    }
    
    int execTop() {

        if(tasks.empty()) return -1;

        auto id=-(tasks.begin()->second);

        int ans= user[id];

        rmv(id);

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