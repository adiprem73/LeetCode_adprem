class Solution {
public:
    vector<vector<int>> findFarmland(vector<vector<int>> &land)
{
    // we will try to solve this using bfs
    int m = land.size();
    int n = land[0].size();

    vector<vector<bool>> vis (m, vector<bool>(n, false));

    queue<pair<int,int>> q;
    vector<vector<int>> ans;

    vector<int> dx = {-1, 0, 1, 0};
    vector<int> dy = {0, 1, 0, -1};
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            vector<int> curr;
            if(land[i][j]==1 && vis[i][j]==false){
                q.push({i,j});
                vis[i][j]= true;
                curr.push_back(i);
                curr.push_back(j);
            }
            int g=-1,h=-1;
            while(!q.empty()){
                auto [x,y] = q.front();
                q.pop();
                g=max(g,x);
                h=max(h,y);
                for(int i=0;i<4;i++){
                    int nx = x+dx[i];
                    int ny = y+dy[i];
                    if(nx>=0 && nx<m && ny>=0 && ny<n && vis[nx][ny] == false && land[nx][ny] == 1){
                        q.push({nx,ny});
                        vis[nx][ny]= true;
                    }
                }
            }
            if(g!=-1 && h!=-1){
                curr.push_back(g);
            curr.push_back(h);
            ans.push_back(curr);
            }
            
        }
    }
    return ans;
}
};