class Solution {
public:
    int orangesRotting(vector<vector<int>> &grid)
{
    int m = grid.size(); // number of rows
    int n = grid[0].size(); // number of cols

    // for such question we always do bfs. since we need to move in four directions and bfs naturally takes the motions of four directions
    // bfs in grpahs requires a queue
    // each entry in the queue will the (i, j, time). 
    // the starting points of the bfs will be those which ocntaitn '2' that is which are rotten
    queue<vector<int>>q;
    vector<int> dx = {0, 1, 0, -1};
    vector<int> dy = {-1, 0, 1, 0};
    int countFresh = 0;
    // here the rottening occurs from each rotten orange at once. and not one by one
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(grid[i][j]==2){
                q.push({i,j,0});
            }else if(grid[i][j]==1){
                countFresh++;
            }
        }
    }

    int ansTime =0;
    
    while(!q.empty()){
        auto node = q.front();
        q.pop();
        int x = node[0];
        int y = node[1];
        int time = node[2];
        ansTime= max(ansTime, time);
        for(int k=0;k<4;k++){
            int nx = x+dx[k];
            int ny = y+dy[k];
            if(nx>=0 && nx<m && ny>=0 && ny<n && grid[nx][ny]==1){
                q.push({nx, ny, time+1});
                grid[nx][ny] = 2;
                countFresh--;
            }
        }
    }
           
    // now if all the cells have been visited, then we can return the ansTime or else we will return -1
    if(countFresh == 0)return ansTime;
    else return -1;
}
};