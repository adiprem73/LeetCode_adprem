class Solution {
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<int>> layers;
    int l=0,r=n-1,u=0,d=m-1;
    while(l<r && u<d){
        vector<int> layer1;
        for (int i = l; i <= r; i++)
        {
            layer1.push_back(grid[u][i]);
        }
        u++;
        for (int i = u; i <= d; i++)
        {
            layer1.push_back(grid[i][r]);
        }
        r--;
        for (int i = r; i >= l; i--)
        {
            layer1.push_back(grid[d][i]);
        }
        d--;
        for (int i = d; i >= u; i--)
        {
            layer1.push_back(grid[i][l]);
        }
        l++;
        layers.push_back(layer1);
    }
    for(auto &it: layers){
        int times = k%(it.size());
        while(times -- ){
            int temp = it[0];
            for (int i = 0; i < it.size() - 1; i++)
            {
                it[i] = it[i + 1];
            }
            it[it.size() - 1] = temp;
        }
    }

    // for(auto &it: layers){
    //     vprint(it);
    // }

    l = 0, r = n - 1, u = 0, d = m - 1;
    int x =0;
    while (l < r && u < d)
    {
        int ind =0;
        for (int i = l; i <= r; i++)
        {
            grid[u][i] = layers[x][ind++];
        }
        u++;
        for (int i = u; i <= d; i++)
        {
            grid[i][r]= layers[x][ind++];
        }
        r--;
        for (int i = r; i >= l; i--)
        {
            grid[d][i]= layers[x][ind++];
        }
        d--;
        for (int i = d; i >= u; i--)
        {
            grid[i][l]= layers[x][ind++];
        }
        l++;
        x++;
    }
    return grid;
}
};