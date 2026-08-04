class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m = image.size();
        int n = image[0].size();
        int conditionColor = image[sr][sc];
        if(conditionColor == color)return image;
        // we will use a BFS approach
        queue<pair<int,int>> q;
        q.push({sr,sc});
        image[sr][sc] = color;
        int dr[] = {-1,0,1,0};
        int dc[] = {0,1,0,-1};
        while(!q.empty()){
            int size= q.size();
            for(int i=0;i<size;i++){
                auto [r,c] = q.front();
                q.pop();
                for(int i=0;i<4;i++){
                    int nr = r+dr[i];
                    int nc = c+dc[i];
                    if(nr>=0 && nr<m && nc>=0 && nc<n){
                        if(image[nr][nc] == conditionColor){
                            image[nr][nc] = color;
                            q.push({nr,nc});
                        }
                    }
                }
            }
        }
        return image;
    }
};