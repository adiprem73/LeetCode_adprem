class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
    int n= mat.size();
    if(!n) return 0;
    int m= mat[0].size();

    // findingt the prefix sum anmtrix
    vector<vector<int>> pref(n+1, vector<int>(m+1, 0));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            pref[i][j]= mat[i-1][j-1]+pref[i][j-1]+pref[i-1][j]- pref[i-1][j-1];
        }
    }
    // now we have made a prefix sum matrix for this array
    


    // cout<<m<<n<<endl;
    int s=0;
    int e= min(n,m);
    // we do binary search on answers
    int ans=0;


    while(s<=e){
        int mid= s+(e-s)/2;
        int k=mid;
        bool flag= false;
        for (int i = 0; i < n - k + 1; i++)
        {
            for (int j = 0; j + k < m + 1; j++)
            {
                int sum= pref[i+k][j+k]-pref[i][j+k]-pref[i+k][j]+pref[i][j];
                if(sum<=threshold){
                    flag= true;
                    break;
                }
            }
            if(flag){
                break;
            }
        }
        if(flag){
            s=mid+1;
            ans=mid;
        }
        else{
            e=mid-1;
        }
    }
    return ans;
}
};