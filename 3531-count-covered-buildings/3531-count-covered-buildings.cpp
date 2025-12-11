class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
    unordered_map<int, set<int> > X,Y;
    for(auto it: buildings){
        X[it[0]].insert(it[1]);
        Y[it[1]].insert(it[0]);        
    }
    int cnt=0;
    // for(auto& p : X) {
    //     cout << p.first << " : ";
    //     for(auto& val : p.second) cout << val << " ";
    //     cout << endl;
    // }
    // cout << endl;
    // for(auto& p : Y) {
    //     cout << p.first << " : ";
    //     for(auto& val : p.second) cout << val << " ";
    //     cout << endl;
    // }
    // cout << endl;
    for(auto it: buildings){
        int x=it[0];
        int y=it[1];
        if(*X[x].begin()==y || *X[x].rbegin()==y || *Y[y].begin()==x || *Y[y].rbegin()==x){
            continue;
        }
        cnt++;
    }
    return cnt;
}
};