class Solution {
public:
    static bool compare(pair<string, int> a, pair<string, int>b){
    if(a.second!=b.second)return a.second<b.second;
    return a.first<b.first;
}



vector<string> watchedVideosByFriends(vector<vector<string>> &watchedVideos, vector<vector<int>> &friends, int id, int level)
{
    queue<pair<int, int>> q; // (id, level)
    q.push({id, 0});
    map<string, int> mp;
    unordered_set<int> vis;
    vis.insert(id);
    while(!q.empty()){
        auto it= q.front();
        q.pop();
        int person= it.first;
        int currlevel= it.second;
        if(currlevel == level){
            for(auto x: watchedVideos[person]){
                mp[x]++;
            }
            continue;
        }
        if(currlevel<level){
            for (auto frnd : friends[person])
            {
                if (vis.find(frnd) == vis.end())
                {
                    q.push({frnd, currlevel + 1});
                    vis.insert(frnd);
                }
            }
        }
         
    }
    // now we need to prepare the vector from t he map
    vector<pair<string, int>> items(mp.begin(), mp.end());
    sort(items.begin(), items.end(), compare);
    vector<string> ans;
    for(auto it: items){
        ans.push_back(it.first);
    }
    return ans;
}
};