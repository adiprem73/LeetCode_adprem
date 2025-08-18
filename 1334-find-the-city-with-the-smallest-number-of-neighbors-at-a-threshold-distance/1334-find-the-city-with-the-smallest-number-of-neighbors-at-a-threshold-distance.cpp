class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
    vector<vector<int>>dist(n,vector<int>(n,1e9));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i==j){
                dist[i][j]=0;
            }
        }
    }

    //preping adj matrix
    for(auto it: edges){
        int from= it[0];
        int to= it[1];
        int wt= it[2];
        dist[from][to]=wt;
        dist[to][from]=wt;
    }

    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                dist[i][j]=min(dist[i][j], dist[i][k]+dist[k][j]);
            }
        }
    }
    
    // for(auto it: dist){
    //     vprint(it);
    // }

    vector<int> temp(n,0);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(dist[i][j]<=distanceThreshold){
                temp[i]++;
            }
        }
    }
    int minimum=INT_MAX;
    for(auto it: temp){
        minimum=min(minimum, it);
    }
    vector<int> ans;
    // for(auto it: temp){
    //     if(it==minimum){
    //         ans.push_back(it);
    //     }
    // }

    for(int i=0;i<temp.size();i++){
        if(temp[i]==minimum){
            ans.push_back(i);
        }
    }

    // cout<<endl;
    // vprint(temp);
    // cout<<endl<<minimum<<endl;
    // cout<<"ans : "<<endl;
    // vprint(ans);
    if(ans.size()==1){
        return ans[0];
    }return ans[ans.size()-1];


    
    return 0;
}
};