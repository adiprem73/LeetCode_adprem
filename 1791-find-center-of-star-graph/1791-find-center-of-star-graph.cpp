class Solution {
public:
    int findCenter(vector<vector<int>> &edges)
{
    int n=INT_MIN;
    for(auto it: edges){
        n=max(n,max(it[0], it[1]));
    }
    vector<vector<int>> gph(n+1);
    for (auto it : edges)
    {
        // cout<<it[0]<<" "<<it[1]<<endl;
        // the two nodes are it[0] and it[1]
        gph[it[0]].push_back(it[1]);
        gph[it[1]].push_back(it[0]);
        // for (auto it : gph)
        // {
        //     vprint(it);
        // }
    }
    // cout<<"HEllo"<<endl;
    // for(auto it: gph){
    //     vprint(it);
    // }
    for (int i = 1; i <= n; i++)
    {
        // vprint(gph[i]);
        if (gph[i].size() == n - 1)
        {
            return i;
        }
    }
    return -1;
}
};