class Solution {
public:
    void addToSet(set<int>& ans, int n){
    ans.insert(n);
    if(ans.size()>3){
        ans.erase(ans.begin());
    }
}

vector<int> getBiggestThree(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();
    set<int> ans;
    for(int r =0;r<m;r++){
        for(int c =0;c<n;c++){
            addToSet(ans, grid[r][c]); //adding the side = 0 into the set as well
            // now we will try for every possible side with this grid[r][c] as the center
            
            for(int size =1; r-size>=0 && r+size<m && c-size>=0 && c+size<n; size++){
                int sum =0;
                for(int k=0;k <= size-1;k++){
                    sum += grid[r-size +k][c+k];
                    sum += grid[r+size-k][c-k];
                    sum += grid[r-k][c-size+k];
                    sum += grid[r+k][c+size-k];
                }
                addToSet(ans, sum);
            }
            
        }
    }   
    vector<int> vec (ans.begin(), ans.end());
    reverse(vec.begin(), vec.end());
    return vec;    
}
};