class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
    int n=image.size();
    int m=image[0].size();

    queue<pair<int,int>> q;
    vector<vector<int>> vis(n, vector<int>(m,0));

    q.push({sr,sc});
    int clr=image[sr][sc];
    image[sr][sc]=color;
    vis[sr][sc]=color;
    
    vector<int> drow={-1,0,1,0};
    vector<int> dcol={0,1,0,-1};

    while(!q.empty()){
        auto node=q.front();
        int r=node.first;
        int c=node.second;
        q.pop();
        for(int i=0;i<4;i++){
            int nrow=r+drow[i];
            int ncol=c+dcol[i];
            if(nrow>=0 && nrow<n && ncol<m && ncol>=0 && vis[nrow][ncol]!= color && image[nrow][ncol]==clr){
                q.push({nrow,ncol});
                image[nrow][ncol]=color;
                vis[nrow][ncol]=color;
            }
        }
        // cout<<"r : "<<r<<" c : "<<c<<endl;
        // for(int i=0;i<image.size();i++){
        //     vprint(image[i]);
        // }
    }
    return image;
}
};