class Solution {
public:
    vector<vector<int>> buildMatrix(int k, vector<vector<int>> &rowConditions, vector<vector<int>> &colConditions)
{
    // first we will paply topo sort to find the orders for both row conditions and col conditions
    // topo sosrt to find the order for rwo conditons
    vector<vector<int>> adjRow (k+1);
    for(auto it: rowConditions){
        adjRow[it[0]].push_back(it[1]);
    }
    // now we have prepared the adjacency vector
    vector<int> indegree(k+1);
    for(auto it: adjRow){
        for(auto itr: it){
            indegree[itr] ++;
        }
    }   
    queue<int> q;
    vector<int> topoRow;
    for(int i=1;i<k+1;i++){
        if(indegree[i]==0){
            q.push(i);
        }
    }

    while(!q.empty()){
        int node = q.front();
        q.pop();
        topoRow.push_back(node);
        for(auto it: adjRow[node]){
            indegree[it]--;
            if(indegree[it]==0){
                q.push(it);
            }
        }
    }

    // now we will need to do the same for column as well
    vector<int> topoCol;
    vector<vector<int>> adjCol(k+1);
    for (auto it : colConditions)
    {
        adjCol[it[0]].push_back(it[1]);
    }
    vector<int> indegree2(k+1);
    for (auto it : adjCol)
    {
        for (auto itr : it)
        {
            indegree2[itr]++;
        }
    }
    queue<int> q2;
    for (int i = 1; i < k+1; i++)
    {
        if (indegree2[i] == 0)
        {
            q2.push(i);
        }
    }

    while (!q2.empty())
    {
        int node = q2.front();
        q2.pop();
        topoCol.push_back(node);
        for (auto it : adjCol[node])
        {
            indegree2[it]--;
            if (indegree2[it] == 0)
            {
                q2.push(it);
            }
        }
    }
    if(topoRow.size() != k) return {};
if(topoCol.size() != k) return {};
    // now we have built the topo row and topo col
    map<int,int> mpRow, mpCol;
    for(int i=0;i<k;i++){
        mpRow[topoRow[i]]= i;
        mpCol[topoCol[i]]= i;
    }

    vector<vector<int>> ans(k, vector<int>(k,0));
    for(int i=1;i<k+1;i++){
        int x = mpRow[i];
        int y = mpCol[i];
        ans[x][y] = i;
    }

    return ans;
}
};