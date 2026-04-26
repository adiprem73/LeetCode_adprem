class Solution {
public:
    void makeSubSets(vector<int>& curr, vector<int> &arr, vector<vector<int>> & combination, int ind, int &n){
    if(ind == n){
        combination.push_back(curr);
        return;
    }

    // pick this index
    curr.push_back(arr[ind]);
    makeSubSets(curr, arr, combination, ind+1, n);

    //back-tracking
    curr.pop_back();

    // do not pick and move ahead
    makeSubSets(curr, arr, combination, ind+1,n);
}

void dfs(int u, vector<vector<int>>& adj, vector<bool>& vis, set<int>& subSet, int &sum, vector<int>& nums){
    vis[u]= true;
    sum+=nums[u]; // take sum
    for(auto neigh: adj[u]){
        if(vis[neigh]==false && subSet.count(neigh)>0){
            dfs(neigh, adj, vis, subSet,sum, nums);
        }
    }
}

int evenSumSubgraphs(vector<int>& nums, vector<vector<int>>& edges) {
    // first we will make a adj matrix
    int n = nums.size();
    vector<vector<int>> adj(n);
    for(auto &it: edges){
        adj[it[0]].push_back(it[1]);
        adj[it[1]].push_back(it[0]);
    }
    // now let us create all possible subsets
    vector<int> arr;
    for(int i=0;i<n;i++){
        arr.push_back(i);
    }
    vector<int> curr;
    vector<vector<int>> combination;
    makeSubSets(curr, arr, combination, 0, n);
    int cnt =0;
    for(int i =0;i<combination.size();i++){
        if (combination[i].empty())
            continue;
        vector<bool> vis(n, false);
        if(combination[i].size()==1){
            if(nums[combination[i][0]] %2 == 0){
                cnt++;
                continue;
            }
        }
        else{
            set<int> subSet(combination[i].begin(), combination[i].end());
            int sum=0;
            dfs(combination[i][0], adj, vis, subSet, sum, nums);
            // for(auto it:vis){
            //     cout<<it<<" ";
            // }
            // cout<<endl;
            // vprint(combination[i]);
            // // cout<<endl;
            // cout<<sum<<endl;
            // cout<<"--------"<<endl;
            bool flag = true;
            for(int j=0;j<combination[i].size();j++){
                if(vis[combination[i][j]]==false){
                    flag = false;
                    break;
                }
            }
            if(flag==false){
                continue; // no need to go further than this
            }
            if(sum%2!=0){
                continue;
            }
            cnt++;
        }
    }
    return cnt;
}
};