class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
    int n = grid.size();
    int ans =0;
    for(int i=0;i<n;i++){
        int rightmostOne = 0;
        int targetRow =-1;
        for(int k = i;k<n;k++){
            int j = 0;
            int rightmost = 0;
            while (j < n)
            {
                if (grid[k][j] == 1)
                    rightmost = j;
                j++;
            }
            if (rightmost <= i){
                rightmostOne= rightmost;
                targetRow = k;
                break;
            }
        }
        if(targetRow == -1){
            return -1;
        }
        while(targetRow>i){
            swap(grid[targetRow], grid[targetRow-1]);
            targetRow--;
            ans++;
        }
        
    }
    return ans;
}
};