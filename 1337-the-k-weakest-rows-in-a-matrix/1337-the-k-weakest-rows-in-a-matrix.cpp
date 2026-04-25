class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>> &mat, int k)
{
    int n = mat.size();
    vector<int> ind;
    map<int,int> mp;
    for(int i =0;i<n;i++){
        ind.push_back(i);
        auto vec = mat[i];
        int cnt =0;
        for(auto it: vec){
            
            if(it == 0){
                break;
            }
            cnt++;
        }
        mp[i] = cnt;
    }
    // mprint(mp);
    sort(ind.begin(), ind.end(), [&](int a, int b){
        if(mp[a] == mp[b]){
            return a<b;
        }
        return mp[a] < mp[b];
    });
    // vprint(ind);
    vector<int> ans (ind.begin(), ind.begin()+k);
    return ans;
}
};