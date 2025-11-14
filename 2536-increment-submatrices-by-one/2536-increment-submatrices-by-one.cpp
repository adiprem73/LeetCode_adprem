class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
    vector<vector<int>> vec(n, vector<int>(n,0));
    for(auto it: queries){
        int r1= it[0];
        int c1= it[1];
        int r2= it[2];
        int c2= it[3];

        for(int i=r1;i<=r2;i++){
            for(int j=c1;j<=c2;j++){
                vec[i][j]+=1;
            }
        }
    }

    // for(auto it: vec){
    //     vprint(it);
    // }
    return vec;
    }
};