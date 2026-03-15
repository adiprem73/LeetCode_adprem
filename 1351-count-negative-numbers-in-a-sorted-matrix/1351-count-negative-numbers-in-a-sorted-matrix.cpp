class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int n = grid.size();
        int ans =0;
        for(int i=0;i<n;i++){
            auto &vec = grid[i];
            int num = vec.size();
            int l =0;
            int r= num-1;
            while(l<r){
                int mid = l+(r-l)/2;
                if(vec[mid]<0){
                    r=mid;
                }else{
                    l= mid+1;
                }
            }
            if(vec[l]<0){
                ans += num - l;
            }
            
        }
        return ans;
    }
};