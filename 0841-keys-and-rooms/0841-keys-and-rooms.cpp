class Solution {
public:
    void dfs(int node, vector<vector<int>>& rooms, vector<bool>& visited){
    visited[node]= true;
    for(auto neigh: rooms[node]){
        if(visited[neigh]== false){
            dfs(neigh, rooms, visited);
        }
    }
}

bool canVisitAllRooms(vector<vector<int>> &rooms)
{
    // adj matrix is only given
    // make a visited array
    int n= rooms.size();
    vector<bool> visited(n);
    // perfomr dfs starting from 0
    dfs(0, rooms, visited);
    for(auto it: visited){
        if(it== false){
            return false;
        }
    }return true;
}
};