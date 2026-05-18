class Solution {
public:
    int minJumps(vector<int> &arr)
{
    int n = arr.size();
    // we will perform simple bfs
    vector<bool> vis(n, false);
    queue<int> q;
    q.push(0);
    vis[0] = true;
    map<int, vector<int>> mp;
    for (int i = 0; i < arr.size(); i++)
    {
        mp[arr[i]].push_back(i);
    }
    // for(auto it:mp){
    //     cout<<it.first<<" : "<<endl;
    //     vprint(it.second);
    // }
    int steps = 0;
    while (!q.empty())
    {
        int size = q.size();
        for (int i = 0; i < size; i++)
        {
            auto ind = q.front();
            q.pop();
            if (ind == n - 1)
            {
                return steps;
            }
            if(ind + 1 < n){
                if (vis[ind+1]== false)
                {
                    q.push(ind + 1);
                    vis[ind + 1] = true;
                }
            }
            if(ind - 1 >= 0){
                if (vis[ind-1]== false)
                {
                    q.push(ind - 1);
                    vis[ind - 1] = true;
                }
            }
            
            
            // if (mp[arr[ind]].size() > 1)
            // {
            //     for (auto it : mp[arr[ind]])
            //     {
            //         if (vis[it] == false)
            //         {
            //             q.push(it);
            //             vis[it] = true;
            //         }
            //     }
            // }
            for(auto it: mp[arr[ind]]){
                if(!vis[it]){
                    q.push(it);
                    vis[it]= true;
                }
            }

            mp[arr[ind]].clear();
            
        }
        steps++;
        // auto copy = q;
        // while (!copy.empty())
        // {
        //     cout << copy.front() << " ";
        //     copy.pop();
        // }
        // cout << endl;
        
    }
    return -1;
}
};