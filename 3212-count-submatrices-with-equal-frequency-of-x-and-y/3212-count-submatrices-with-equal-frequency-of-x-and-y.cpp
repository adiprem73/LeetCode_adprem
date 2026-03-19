class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<pair<int,int>>> count(m, vector<pair<int,int>> (n,{0,0}));
        for(int i = 0; i < m; i++){
    for(int j = 0; j < n; j++){
        
        if(grid[i][j] == 'X') count[i][j].first = 1;
        if(grid[i][j] == 'Y') count[i][j].second = 1;

        if(i > 0){
            count[i][j].first += count[i-1][j].first;
            count[i][j].second += count[i-1][j].second;
        }
        if(j > 0){
            count[i][j].first += count[i][j-1].first;
            count[i][j].second += count[i][j-1].second;
        }
        if(i > 0 && j > 0){
            count[i][j].first -= count[i-1][j-1].first;
            count[i][j].second -= count[i-1][j-1].second;
        }
    }
}
        int cnt =0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(count[i][j].first!=0 && count[i][j].first== count[i][j].second){
                    cnt++;
                }
            }
        }
        return cnt;
    }
};