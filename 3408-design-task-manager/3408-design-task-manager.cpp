class TaskManager
{

private:
    priority_queue<array<int, 3>> data; //(priority, taskId, userId)
    unordered_map<int, pair<int,int>> mp; // for optimisations of the code

public:
    TaskManager(vector<vector<int>> &tasks)
    {
        for (auto it : tasks)
        {
            data.push({it[2], it[1], it[0]});
            mp[it[1]]={it[2], it[0]}; // taskid ===> {priority, userid}
        }
        
    }

    void add(int userId, int taskId, int priority)
    {
        data.push({priority, taskId, userId});
        // data2.push_back({userId, taskId, priority});
        mp[taskId]={priority, userId};
    }

    void edit(int taskId, int newPriority)
    {
        mp[taskId].first=newPriority;
        data.push({newPriority, taskId, mp[taskId].second});
    }

    void rmv(int taskId)
    {
        mp.erase(taskId);
    }

    int execTop()
    {
        // priority_queue<array<int, 3>> copy=data;
        // cout<<"map : "<<endl;
        // for(auto it: mp){
        //     cout<<it.first<<" "<<it.second.first<<" "<<it.second.second<<endl;
        // }
        // cout<<"data : "<<endl;
        // while(!copy.empty()){
        //     auto top = copy.top();
        //     int pri = top[0];
        //     int tid = top[1];
        //     int uid = top[2];
        //     cout<<tid<<" "<<pri<<" "<<uid<<endl;
        //     copy.pop();
        // }

        while (!data.empty())
        {
            auto top = data.top(); data.pop();
            int pri = top[0];
            int tid = top[1];
            int uid = top[2];
            bool flag = false;
            auto it= mp.find(tid);
            if(it!=mp.end()){
                if (mp[tid].first == pri && mp[tid].second == uid)
                {
                    mp.erase(tid);
                    return uid;
                }

            }
            
        }
        return -1;
    }
};