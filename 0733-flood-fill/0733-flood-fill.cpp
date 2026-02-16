class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color)
{
    int m = image.size();
    int n = image[0].size();
    // let us do this quesitons by using BFS
    queue<pair<int,int>>q;
    q.push({sr,sc});
    vector<int> dx = {-1, 0, 1 , 0};
    vector<int> dy = {0, 1, 0, -1};
    vector<vector<bool>> visited(m, vector<bool>(n,false));
    visited[sr][sc]= true;
    while(!q.empty()){
        // we mustmove in all four directions 
        auto [x, y] = q.front();
        q.pop();
        int prevcolor = image[x][y];
        image[x][y]= color;
        // we do not need to perform layer by layer bfs so we will jsut do normal bfs
        for(int i=0;i<4;i++){
            int nx = x+dx[i];
            int ny = y+dy[i];
            if(nx>=0 && nx<m && ny>=0 && ny<n && visited[nx][ny]==false && image[nx][ny] == prevcolor){
                q.push({nx, ny});
                visited[nx][ny] = true;
            }
        }
    }
    return image;
}
};