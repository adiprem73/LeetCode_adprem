class Solution {
public:
    int findJudge(int n, vector<vector<int>> &trust)
{
    if(trust.size()==0){
        if(n>1)return -1;
        else return n;
    }
    if(trust.size()==1 && trust[0].size()==0){
        if(n>1)return -1;
        else return n;
    }
    vector<vector<int>> gp(n+1);
    for(auto it: trust){
        gp[it[0]].push_back(it[1]);
    }
    // graph is ready
    vector<int> judgeCandidates; //ones who dont have anybody who they trust
    for(int i=1;i<=n;i++){
        if(gp[i].size()==0){
            judgeCandidates.push_back(i);
        }
    }
    // now we just need to search others. search for whom does everyone trust
    for(int it: judgeCandidates){
        bool flag=true;
        for (int i = 1; i <= n; i++)
        {
            if (i!=it)
            {
                if(find(gp[i].begin(), gp[i].end(), it)==gp[i].end()){
                    flag=false;
                    break;
                }
            }
        }
        if(flag==true){
            return it;
        }
    }return -1;
    
}
};