class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int> &groupSizes)
{
    int n= groupSizes.size();
    set<int> grp;
    for(auto it: groupSizes){
        grp.insert(it);
    }
    vector<vector<int>> ans;
    for(auto it: grp){
        vector<int> currGrp;
        for(int i=0;i<n;i++){
            if(groupSizes[i]==it){
                currGrp.push_back(i);
            }
            if(currGrp.size()== it){
                ans.push_back(currGrp);
                currGrp.clear();
            }
        }
    }
    return ans;
}
};