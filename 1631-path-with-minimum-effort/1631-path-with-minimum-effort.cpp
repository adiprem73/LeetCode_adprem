class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
    //{difference,{row,col}}
    priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>> > pq;

    int n=heights.size();
    int m=heights[0].size();

    vector<vector<int>> diff(n, vector<int> (m,1e9));
    pq.push({0,{0,0}});
    diff[0][0]=0;

    vector<int> drow={-1,0,1,0};
    vector<int> dcol={0,1,0,-1};

    while(!pq.empty()){
        auto it = pq.top();
        pq.pop();
        int difference= it.first;
        int r=it.second.first;
        int c=it.second.second;

        if(r==n-1 && c==m-1)return difference;

        for(int i=0;i<4;i++){
            int nrow=r+drow[i];
            int ncol=c+dcol[i];

            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m ){
                int newEffort= max(abs(heights[r][c]-heights[nrow][ncol]), difference);
                if(newEffort < diff[nrow][ncol]){
                    pq.push({newEffort,{nrow,ncol}});
                    diff[nrow][ncol]= newEffort;
                }
            }
        }
    }
    return 0;
}
};