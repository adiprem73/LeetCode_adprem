class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        // since this is step by step thing, we will use BFS for this questions

        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int,int>> q;
        int emptyGrid=true;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
            if(grid[i][j]!=0){
                emptyGrid= false;
            }
            if(grid[i][j]==2){
                q.push({i,j});
            }
        }
        }
        if(emptyGrid)return 0;
        vector<int> dr = {-1,0,1,0};
        vector<int> dc = {0,1,0,-1};
        int minutes=-1;
        while(!q.empty()){
            int size = q.size();
            minutes++;
            for(int i=0;i<size;i++){
                auto [r,c] = q.front();
                q.pop();
                for(int i=0;i<4;i++){
                    int nr = r+dr[i];
                    int nc = c+dc[i];

                    // checking conditions
                    if(nr>=0 && nr<m && nc>=0 && nc<n && grid[nr][nc] == 1){
                        q.push({nr,nc});
                        grid[nr][nc] = 2;
                    }
                }
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 1){
                    return -1;
                }
            }
        }

        return minutes;
    }
};