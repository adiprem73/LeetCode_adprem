class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        int m = grid.size();
        int n = grid[0].size();
        for(int i = 0;i < k;i++){
            int c = i+y;
            int rs= x;
            int re= x+k-1;
            while(rs<re && re<m){
                swap(grid[rs][c], grid[re][c]);
                rs++;
                re--;
            }
                
        }
        return grid;
    }
};