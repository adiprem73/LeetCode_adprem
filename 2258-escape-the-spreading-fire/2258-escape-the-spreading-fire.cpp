class Solution {
public:
    void updateFireTime(vector<vector<int>> &grid, vector<vector<int>> &fireTime){
    int m = grid.size();
    int n = grid[0].size();

    queue<pair<int,int>> q;

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(grid[i][j]==1){
                q.push({i,j});
                fireTime[i][j]=0;
            }else{
                fireTime[i][j]=INT_MAX;
            }
        }
    }

    vector<int> dx = {-1,0,1,0};
    vector<int> dy = {0,1,0,-1};

    while(!q.empty()){
        auto [x,y] = q.front();
        q.pop();

        for(int d=0; d<4; d++){
            int nx = x + dx[d];
            int ny = y + dy[d];

            if(nx>=0 && ny>=0 && nx<m && ny<n && grid[nx][ny] != 2){
                if(fireTime[nx][ny] > fireTime[x][y] + 1){
                    fireTime[nx][ny] = fireTime[x][y] + 1;
                    q.push({nx,ny});
                }
            }
        }
    }
}

bool canEscape(int wait,
               vector<vector<int>> &fireTime,
               vector<vector<int>> &grid){

    int m = grid.size();
    int n = grid[0].size();

    if(wait >= fireTime[0][0]) return false;

    queue<pair<int,int>> q;
    vector<vector<bool>> vis(m, vector<bool>(n,false));

    q.push({0,0});
    vis[0][0] = true;

    int time = wait;

    vector<int> dx = {-1,0,1,0};
    vector<int> dy = {0,1,0,-1};

    while(!q.empty()){
        int sz = q.size();
        time++;

        while(sz--){
            auto [x,y] = q.front();
            q.pop();

            for(int d=0; d<4; d++){
                int nx = x + dx[d];
                int ny = y + dy[d];

                if(nx<0||ny<0||nx>=m||ny>=n) continue;
                if(vis[nx][ny] || grid[nx][ny]==2) continue;

                // destination cell
                if(nx==m-1 && ny==n-1){
                    if(time <= fireTime[nx][ny])
                        return true;
                    else
                        continue;
                }

                if(time < fireTime[nx][ny]){
                    vis[nx][ny]=true;
                    q.push({nx,ny});
                }
            }
        }
    }
    return false;
}

int maximumMinutes(vector<vector<int>> &grid)
{
    int m = grid.size();
    int n = grid[0].size();

    vector<vector<int>> fireTime(m, vector<int>(n,INT_MAX));
    updateFireTime(grid, fireTime);

    int left = 0;
    int right = 1e9;
    int ans = -1;

    while(left <= right){
        int mid = left + (right-left)/2;

        if(canEscape(mid, fireTime, grid)){
            ans = mid;
            left = mid + 1;
        }
        else
            right = mid - 1;
    }

    return ans == 1e9 ? 1e9 : ans;
}

};