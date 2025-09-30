class Solution {
public:
        vector<double> calcEquation(vector<vector<string>> &equations, vector<double> &values, vector<vector<string>> &queries)
{
    int n=equations.size();
    
    unordered_map<string,vector<pair<string, double>>> mp;
    for (int i = 0; i <equations.size();i++){
        mp[equations[i][0]].push_back({equations[i][1], (double)values[i]});
        mp[equations[i][1]].push_back({equations[i][0], (double)1.0/values[i]});
    }

    vector<double> ans;
    ans.reserve(queries.size());
    for(auto & q: queries){
        string source= q[0];
        string destination= q[1];
        
        if(!mp.count(source) || !mp.count(destination)) {
            ans.push_back(-1.0);
            continue;
        }
        if(source == destination) {
            ans.push_back(1.0);
            continue;
        }

        // now we need to perform BFS
        unordered_set<string> vis;
        queue<pair<string, double>> qq;
        qq.push({source, 1.0});

        double found=-1.0;

        while(!qq.empty()){
            auto it= qq.front();
            string node= it.first;
            double wt= it.second;
            qq.pop();
            if(node == destination){
                found=wt;
                break;
            }

            for(auto iter: mp[node]){
                string adjnode = iter.first;
                double adjWt = iter.second;
                if(!vis.count(adjnode)){
                    vis.insert(adjnode);
                    qq.push({adjnode, wt*adjWt});
                }
            }

        }
        ans.push_back(found);
    }
    return ans;
}
};